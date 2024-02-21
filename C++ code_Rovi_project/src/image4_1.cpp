#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>

#include "functions.cpp"
#include <iostream>

using namespace cv;
void displayHistMag( std::string name, Mat img);

Mat notchPairFilter(Mat &img,std::vector<Size> centers, std::vector<int> radius,int order)
{
    int opt_rows = getOptimalDFTSize(img.rows*2-1);
    int opt_cols = getOptimalDFTSize(img.cols*2-1);
    Size size(opt_cols,opt_rows);
    //Mat filter;

    Mat_<Vec2f> notchButter(size,CV_32F);
    int centerx,centery;
    centerx = size.width/2;
    centery = size.height/2;
    std::vector<Point2f> c;
    std::vector<int> r;

    for (int i = 0; i < centers.size(); i++)
    {
        c.push_back(Point2f(Size(centerx+centers[i].width,centery+centers[i].height)));
        c.push_back(Point2f(Size(centerx+centers[i].width*-1,centery+centers[i].height*-1)));
        r.push_back(radius[i]);
        r.push_back(radius[i]);

    }

    for(int i = 0; i < size.height; i++)
    {
        for(int j = 0; j < size.width; j++)
        {
            for(int k = 0; k < c.size(); k++)
            {
                float d = std::sqrt((i - c[k].y)*(i - c[k].y)+(j - c[k].x)*(j - c[k].x));
                if (std::abs(d) < 1.e-8f) // Avoid division by zero
                    notchButter(i, j)[0] = 0;
                else
                {
                    notchButter(i, j)[0] = notchButter(i, j)[0]*(float)(1.0 / (1.0 + std::pow(((double)(r[k]/d)),(double)(2.0 * order))));
                }
                notchButter(i, j)[1] = 0;
            }

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
    std::string name = "@image41";
    std::string filepath = parser.get<std::string>(name);
    Mat img = imread(filepath);




    // Check that the image file was actually loaded
    if (img.empty()) {
            std::cout << "Input image not found at '" << filepath << "'\n";
            return 1;
    }
    cvtColor(img, img, COLOR_BGR2GRAY);
    Mat out,filter;
    std::vector<Size> notchcenters;
    std::vector<int> notchradius;
    notchcenters.push_back(Size(200,205));
    notchcenters.push_back(Size(605,-625));
    notchradius.push_back(25);
    notchradius.push_back(40);
    filter = notchPairFilter(img,notchcenters,notchradius,3);


    Mat filter_planes[2];
    split(filter, filter_planes); // We can only display the real part
    normalize(filter_planes[0], filter_planes[0], 0, 1, cv::NORM_MINMAX);
    namedWindow("Filter", WINDOW_NORMAL);
    resizeWindow("Filter", img.cols*0.3, img.rows*0.3);

    imshow("Filter", filter_planes[0]);//filter_planes[0]);





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
