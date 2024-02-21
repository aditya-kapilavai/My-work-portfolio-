/*
   RoVi1
   Example application to load and display an image.


   Version: $$version$$
 */
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>

#include "functions.cpp"
#include <iostream>

using namespace cv;
void displayHistMag( std::string name, Mat img);
Mat butter_lowpass(float d0, int n, Size size);
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
    std::string name = "@image42";
    std::string filepath = parser.get<std::string>(name);
    Mat img = imread(filepath);




    // Check that the image file was actually loaded
    if (img.empty()) {
            std::cout << "Input image not found at '" << filepath << "'\n";
            return 1;
    }
    cvtColor(img, img, COLOR_BGR2GRAY);

    int opt_rows = getOptimalDFTSize(img.rows*2-1);
    int opt_cols = getOptimalDFTSize(img.cols*2-1);
    Size size(opt_cols,opt_rows);
    Mat out,filter;

    Mat_<Vec2f> BandPassFilter(size);
    int x,y,radius,radiusW,order,ik,jk;
    x = size.width/2;
    y = size.height/2;
    radius = 900;
    radiusW = 800;
    order = 40;
    ik = 0;
    jk = 0;
    Point2f c = Point2f(Size(x,y));

    for(int i = 0; i < size.height; i++)
    {
        for(int j = 0; j < size.width; j++)
        {
            float dk = std::sqrt((i - c.y-ik)*(i - c.y-ik)+(j - c.x-jk)*(j - c.x-jk));
            float dnk = std::sqrt((i - c.y+ik)*(i - c.y+ik)+(j - c.x+jk)*(j - c.x+jk));

            if (std::abs(dk) < 1.e-8f) // Avoid division by zero
                BandPassFilter(i, j)[0] = 0;
            else
            {
                BandPassFilter(i, j)[0] = (1 / (1 + std::pow(radius/dk, order))) * (1 / (1 + std::pow(radius/dnk, order)));

                BandPassFilter(i, j)[0] += 1-(1 / ((1 + std::pow(radiusW/dk, order))) * (1 / (1 + std::pow(radiusW/dnk, order))));
            }
            BandPassFilter(i, j)[1] = 0;
        }
    }
    filter = BandPassFilter.clone();

    Mat filter_planes[2];
    split(filter, filter_planes); // We can only display the real part
    normalize(filter_planes[0], filter_planes[0], 0, 1, cv::NORM_MINMAX);
    namedWindow("Filter", WINDOW_NORMAL);
    resizeWindow("Filter", img.cols*0.3, img.rows*0.3);

    imshow("Filter", filter_planes[0]);//filter_planes[0]);





    out = filterMag(img,filter);

    displayHistMag(name, img);
    displayHistMag(name+ "output", out);
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
    resizeWindow(name+" Magnitude", img.cols*0.3, img.rows*0.3);
    imshow(name+" Magnitude", magimg);

}

 /*
    int opt_rows = getOptimalDFTSize(img.rows*2 - 1);
    int opt_cols = getOptimalDFTSize(img.cols*2 - 1);
    Size size(opt_cols,opt_rows);
    Mat mag2 = Mat(size,CV_8U,Scalar(255, 255,255));
    cv::rectangle(mag2, cv::Rect(opt_cols/2-100,opt_rows/2-100,200,200), cv::Scalar(0, 0,0), -1,0,0);
    mag2 = returnFilterMagPhase(mag2);

    Mat_<float> kernel(3, 3);
    kernel << -1,  -2,  -1,
              0, 0, 0,
              1,  2,  1;
    filter2D(out, out, -1, kernel/8, Point(-1, -1), 0, BORDER_REPLICATE);


  */
