#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>

#include "functions.cpp"
#include <iostream>

using namespace cv;
void displayHistMag( std::string name, Mat img);

Mat bandPassFilter(Mat& img, int C0,int W, int order)
{
    int opt_rows = getOptimalDFTSize(img.rows*2-1);
    int opt_cols = getOptimalDFTSize(img.cols*2-1);
    Size size(opt_cols,opt_rows);

    Mat_<Vec2f> notchButter(size,CV_32F);
    int centerx,centery;
    centerx = size.width/2;
    centery = size.height/2;
    Point2f c = Point2f(Size(centerx,centery));

    for(int i = 0; i < size.height; i++)
    {
        for(int j = 0; j < size.width; j++)
        {

            float d = std::sqrt((i - c.y)*(i - c.y)+(j - c.x)*(j - c.x));
            if (std::abs(d) < 1.e-8f) // Avoid division by zero
                notchButter(i, j)[0] = 0;
            else
            {
                notchButter(i, j)[0] = 1/(1+pow(((d*W)/((d)*(d)-C0*C0)),2.0*order));
            }
            notchButter(i, j)[1] = 0;


        }
    }
    //Mat filter = notchButter.clone();


    Mat filter_planes[2];
    split(notchButter, filter_planes); // We can only display the real part
    normalize(filter_planes[0], filter_planes[0], 0, 1, cv::NORM_MINMAX);
    namedWindow("Filter", WINDOW_NORMAL);
    resizeWindow("Filter", img.cols*0.3, img.rows*0.3);

    imshow("Filter", filter_planes[0]);//filter_planes[0]);
    return notchButter;

}
int main(int argc, char* argv[])
{

    CommandLineParser parser(argc, argv,
                                 // name    | default value                      | help message
                                 "{help     |                                    | print this message}"
                                 "{@imageO  | ./images/ImageOrig.png       | image path}"
                                 "{@image1  | ./images/Image1.png          | image path}"
                                 "{@image2  | ./images/Image2.png          | image path}"
                                 "{@image3  | ./images/Image3.png          | image path}"
                                 "{@image41 | ./images/Image4_1.png        | image path}"
                                 "{@image42 | ./images/Image4_2.png        | image path}"
                                 "{@image5  | ./images/Image5_optional.png | image path}"
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

    Mat out,filter;
    filter = bandPassFilter(img,825,100,3);




    out = filterMag(img,filter);

    displayHistMag(name, img);
    displayHistMag(name+ "output", out);
    out.convertTo(out,CV_8U,255);
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
    resizeWindow(name+" Magnitude", img.cols*0.3, img.rows*0.3);
    imshow(name+" Magnitude", magimg);

}
