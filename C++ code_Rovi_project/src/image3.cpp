#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>

#include "functions.cpp"
#include <iostream>

using namespace cv;
void displayHistMag( std::string name, Mat img);



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
    std::string name = "@image3";
    std::string filepath = parser.get<std::string>(name);
    Mat img = imread(filepath);



    // Check that the image file was actually loaded
    if (img.empty()) {
            std::cout << "Input image not found at '" << filepath << "'\n";
            return 1;
    }
    cvtColor(img, img, COLOR_BGR2GRAY);
    Mat out = img.clone();
    Mat out2 = img.clone();


    GaussianBlur(out,out,Size(5,5),0,0);
    out = out -25;

    out2 = alphaTrimFilter(out2, 12, 5);
    //out2 = out2 - 25;

    displayHistMag(name, img);
    displayHistMag(name+ "output", out);
    displayHistMag(name+ "output2", out2);

    imshow("Small hist", drawHist(img));


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
