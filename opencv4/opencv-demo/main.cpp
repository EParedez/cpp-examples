#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using std::cout;
using std::endl;

using namespace cv;

void drawText(Mat & image);

int main(int argc, char** argv) {

    // if (argc != 2) {
    //     cout << "Expecting a image file to be passed to program" << endl;
    //     return -1;
    // }
    
    // cv::Mat img = cv::imread(argv[1]);
    
    // if (img.empty()) {
    //     cout << "Not a valid image file" << endl;
    //     return -1;
    // }
    
    // cv::namedWindow("Simple Demo", cv::WINDOW_AUTOSIZE);
    // cv::imshow("Simple Demo", img);
    
    // cv::waitKey(0);
    // cv::destroyAllWindows();

    cout << "Built with OpenCV" << endl;
    Mat image;
    VideoCapture capture;
    capture.open(0);

    if(capture.isOpened())
    {
        cout << "Capture is opened" << endl;
        for(;;)
        {
            capture >> image;
            if(image.empty())
                break;
            
            drawText(image);
            imshow("Sample", image);
            if(waitKey(10) >= 0)
                break;
        }
    }
    else 
    {
            cout << "No capture" << endl;
            image = Mat::zeros(480, 640, CV_8UC1);
            drawText(image);
            imshow("Sample", image);
            waitKey(0);
    }

    return 0;
}

void drawText(Mat & image)
{
    putText(image, "Hello openCV",
        Point(20, 50),
        FONT_HERSHEY_COMPLEX, 1,
        Scalar(255, 255, 255),
        1, LINE_AA
        );
}