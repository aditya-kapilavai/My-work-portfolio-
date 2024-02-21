#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>

#include "functions.cpp"
#include <iostream>

using namespace cv;
void displayHistMag( std::string name, Mat img);
int levelB(int min, int max, int med, int pixelValue)
{
    if (min < pixelValue)
        if (pixelValue < max)
            return pixelValue;
    return med;
}
int levelA(Mat& img,int x,int y,int k, int sizeOfKernelMax)
{
    int pixelValue,med,min,max;
    pixelValue = img.at<uchar>(x,y);

    int kernelSize = k*2 + 1;
    Mat_<float> kernel(1,kernelSize* kernelSize);
    int alpha = 0;
    for (int i = 0; i < kernelSize; i++)
    {
        for (int j = 0; j < kernelSize; j++)
        {
            kernel(alpha) = img.at<uchar>(x-k+j,y-k+i);
            alpha++;
        }
    }

    sort(kernel,kernel,SORT_ASCENDING);
    med = kernel((kernelSize*kernelSize - 1)/2);
    min = kernel(0);
    max = kernel(kernelSize*kernelSize - 1);
    if (min < med)
    {
        if (med < max)
        {
            k = 1;
            return levelB(min,max,med,pixelValue);
        }
    }
    if(k < sizeOfKernelMax)
    {
            k++;
            return levelA(img,x,y,k,sizeOfKernelMax);
    }
    else
    {
        return med;
    }

           return med;

}

Mat adaptiveMedianFilter(Mat img,int maxk)
{
    Mat out = img.clone();
    for (int x = 0; x < img.rows; x++)
    {
        for (int y = 0; y < img.cols; y++)
        {
            out.at<uchar>(x,y) = levelA(img,x,y,1,maxk);
        }
    }
    return out;
}


/*int aplhaTrim(Mat& img, int d,int k, int x, int y)
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
}*/
/*Mat alphaTrimFilter(Mat& img, int d, int k)
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
}*/


int main(int argc, char* argv[])
{

    CommandLineParser parser(argc, argv,
                             // name    | default value                      | help message
                             "{help     |                                    | print this message}"
                             "{@imageO  | ./../../images/ImageOrig.png       | image path}"
                             "{@image1  | ./../../images/Image1.png          | image path}"
                             "{@image2  | ./../../images/Image2.png          | image path}"
                             "{@image3  | ./../../images/Image3.png          | image path}"
                             "{@image41 | ./../../images/Image4_1.png        | image path}"
                             "{@image42 | ./../../images/Image4_2.png        | image path}"
                             "{@image5  | ./../../images/Image5_optional.png | image path}"
                                 );

    if (parser.has("help")) {
            parser.printMessage();
            return 0;
    }

    // Load image file
    std::string name = "@image2";
    std::string filepath = parser.get<std::string>(name);
    Mat img = imread(filepath);



    // Check that the image file was actually loaded
    if (img.empty()) {
            std::cout << "Input image not found at '" << filepath << "'\n";
            return 1;
    }
    cvtColor(img, img, COLOR_BGR2GRAY);
    Mat out = img.clone();

    out = adaptiveMedianFilter(out,10); //100
    GaussianBlur(out,out,Size(5,5),0,0);

    displayHistMag(name, img);
    displayHistMag(name+ "output", out);

    Mat histCorrupt = drawHist(img);
    histCorrupt = invert_image(histCorrupt);

    imshow("Small hist", histCorrupt);
    imwrite(name+"small hist"+".png", histCorrupt);

    imwrite(name+"output"+".png", out);

    while (waitKey() != 27) // esc key
            ; // (do nothing)
    std::cout << "End of program" << std::endl;
    return 0;
}

void displayHistMag( std::string name, Mat img)
{
    Mat histimg, magimg;
    histimg = drawHist(img);
    magimg = drawMag(img);
    magimg.convertTo(magimg,CV_8U,255);
    imwrite(name+"Magnitude"+".png", magimg);
    imwrite(name+"Histogram"+".png", histimg);
    namedWindow(name, WINDOW_NORMAL);
    resizeWindow(name, img.cols*0.3, img.rows*0.3);
    imshow(name, img);
    imshow(name+" Histogram", histimg);

    namedWindow(name+" Magnitude", WINDOW_NORMAL);
    resizeWindow(name+" Magnitude", magimg.cols*0.1, magimg.rows*0.1);
    imshow(name+" Magnitude", magimg);

}
