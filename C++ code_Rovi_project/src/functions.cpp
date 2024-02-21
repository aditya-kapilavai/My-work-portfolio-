#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;
Mat drawHist(Mat& img)
{
    if (img.type() != CV_8UC1)
    {
       img.convertTo(img, CV_8UC1,255);
       std::cout << "image not CV_8UC1 but converted too CV_8UC1 " << std::endl;
    }

    //assert(img.type() == CV_8UC1);
    Mat hist;
    calcHist(
        std::vector<Mat>{img(Rect(0,0,200,200))},
        {0}, // channels
        noArray(), // mask
        hist, // output histogram
        {256}, // histogram sizes (number of bins) in each dimension
        {0, 256} // pairs of bin lower (incl.) and upper (excl.) boundaries in each dimension
    );
    int bins = hist.rows;
    // making a image with the dimentions of the histogramed picture
    // Then normalizing the hist values so that the values are between 0 and 255
    // Then drawing on the image
    int enhanceHist = 2; // used too make the image bigger whichis nice for us
    int enhancedBins = bins*enhanceHist;
    //int bin_w = cvRound( (double) hist_w/histSize[0] );
    Mat histImage(enhancedBins, enhancedBins, CV_8UC1, Scalar(0) );

    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    for( int i = 0; i < 256; i++ )
    {
        rectangle(histImage, Rect(i*enhanceHist, enhancedBins-hist.at<float>(i),enhanceHist,enhancedBins), Scalar(255), -1,0,0);
        //line( histImage, Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ) ,Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ), Scalar( 255));
    }
    return histImage;
}

void dftshift(Mat& mag)
{
    int cx = mag.cols / 2;
    int cy = mag.rows / 2;

    Mat tmp;
    Mat q0(mag, Rect(0, 0, cx, cy));
    Mat q1(mag, Rect(cx, 0, cx, cy));
    Mat q2(mag, Rect(0, cy, cx, cy));
    Mat q3(mag, Rect(cx, cy, cx, cy));

    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
}

Mat drawMag(Mat& img)
{

    //assert(img.type() == CV_8UC1);
    Mat padded;
    int opt_rows = getOptimalDFTSize(img.rows*2-1);
    int opt_cols = getOptimalDFTSize(img.cols*2-1);
    // On the border add zero values
    copyMakeBorder(img, padded,0, opt_rows - img.rows, 0 , opt_cols - img.cols, BORDER_CONSTANT, Scalar::all(0));

    // Make place for both the real and complex values by merging planes into a
    // Mat with 2 channels.
    // Use float element type because frequency domain ranges are large.
    Mat planes[] = {
        Mat_<float>(padded),
        Mat_<float>::zeros(padded.size())
    };
    Mat complex;
    // Add to the expanded another plane with zeroes
    merge(planes,2, complex);
    // this way the result may fit in the source matrix

    // Compute DFT
    dft(complex, complex);
    // Split real and complex planes
    split(complex, planes);
    // Compute the magnitude and phase
    Mat mag;
    magnitude(planes[0], planes[1], mag);// planes[0] = magnitude

    dftshift(mag);
    mag += Scalar::all(1);
    log(mag, mag);

    // Transform the matrix with float values into a viewable image form (float
    // values between 0 and 1) and show the result.
    normalize(mag, mag, 0, 1, NORM_MINMAX);
    return mag;
}

Mat filterMag(Mat& img, Mat& inputFilter)
{
    Mat filter = inputFilter.clone();
    Mat padded;
    int opt_rows = getOptimalDFTSize(img.rows*2 - 1);
    int opt_cols = getOptimalDFTSize(img.cols*2 - 1);
    copyMakeBorder(img, padded, 0, opt_rows - img.rows, 0, opt_cols - img.cols,
                       BORDER_CONSTANT, Scalar::all(0));

    // Make place for both the real and complex values by merging planes into a
    // Mat with 2 channels.
    // Use float element type because frequency domain ranges are large.
    Mat planes[] = {
        Mat_<float>(padded),
        Mat_<float>::zeros(padded.size())
    };
    Mat complex;
    merge(planes, 2, complex);

    // Compute DFT of image
    dft(complex, complex);

    // Shift quadrants to center
    dftshift(complex);
    // Multiply Fourier image with filter
    mulSpectrums(complex, filter, complex, 0);


    // Shift back
    dftshift(complex);

    // Compute inverse DFT
    Mat filtered;
    idft(complex, filtered, (DFT_SCALE | DFT_REAL_OUTPUT));

    // Crop image (remove padded borders)
    filtered = Mat(filtered, Rect(Point(0, 0), img.size()));

    normalize(filtered, filtered, 0, 1, cv::NORM_MINMAX);
    return filtered;
}

Mat returnFilterMagPhase(Mat& filterimg)
{
    Mat planes[] = {
        Mat_<float>(filterimg),
        Mat_<float>::zeros(filterimg.size())
    };
    Mat complex;
    merge(planes, 2, complex);

    return complex;
}

int aplhaTrim(Mat& img, int d,int k, int x, int y)
{
    int kernelSize =k*2 + 1;
    Mat_<float> kernel(kernelSize, kernelSize);
    for (int i = 0; i < kernelSize; i++)
    {
        for (int j = 0; j < kernelSize; j++)
        {
            kernel[i][j]= img.at<uchar>(x-k+j,y-k+i);
        }
    }
    float sum;

    sum = 0;
    for(int i = 0; i < kernelSize*kernelSize; i++)
        sum = sum + kernel(i);

    if (d > kernelSize*kernelSize)
        d = kernelSize*kernelSize - 1;

    int aplha_trim;
    aplha_trim = (1.0/(kernelSize*kernelSize-d))*sum;
    return aplha_trim;
}
Mat alphaTrimFilter(Mat& img, int d, int k)
{
    Mat out = img.clone();
    for (int x = 0; x < img.rows; x++)
      {
          for (int y = 0; y < img.cols; y++)
          {
             out.at<uchar>(x,y) = aplhaTrim(img, d,k, x, y);

          }
      }
    return out;
}

Mat invert_image(Mat& input)
{
    return 255 - input;
}

