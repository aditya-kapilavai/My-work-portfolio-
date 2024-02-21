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
int contraharmonicFilter(Mat img, float Qorder,int k, int x, int y)
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
    float den,num;
    den = 0;
    num = 0;
    for(int i = 0; i < kernelSize*kernelSize; i++)
        num = num + pow(kernel(i),Qorder+1);

    for(int i = 0; i < kernelSize*kernelSize; i++)
        den = den + pow(kernel(i),Qorder);
    if(den <= 0)
        den = 1;

    int contraharmonic;
    contraharmonic = num/den;
    return contraharmonic;
}

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
    std::string name = "@image1";
    std::string filepath = parser.get<std::string>(name);
    Mat img = imread(filepath);

    // Check that the image file was actually loaded
    if (img.empty()) {
            std::cout << "Input image not found at '" << filepath << "'\n";
            return 1;
    }
    cvtColor(img, img, COLOR_BGR2GRAY);
    Mat out = img.clone();
     for (int x = 0; x < img.rows; x++)
       {
           for (int y = 0; y < img.cols; y++)
           {
              out.at<uchar>(x,y) = contraharmonicFilter(img, 1.5,3, x, y);

           }
       }
    displayHistMag("image1", img);
    displayHistMag(name+ "output", out);
    imwrite(name+"output"+".png", out);

    Mat histCorrupt = drawHist(img);
    histCorrupt = invert_image(histCorrupt);

    imshow("Small hist", histCorrupt);
    imwrite(name+"smallHist"+".png", histCorrupt);

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
