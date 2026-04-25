#include <iostream>
#include <string>
#include<opencv2/opencv.hpp>


int main (){
    cv::VideoCapture video(0, cv::CAP_V4L2);

    cv::Mat frame;

    cv::namedWindow("Test", cv::WINDOW_NORMAL);
    cv::resizeWindow("Test", 800,600);

    video.read(frame);

    // cv::Mat gaussian_blur = (cv::Mat_<double>(3, 3) <<
    //     1.0/9, 1.0/9, 1.0/9,
    //     1.0/9, 1.0/9, 1.0/9,
    //     1.0/9, 1.0/9, 1.0/9
    // );


    while (video.isOpened()){
       
       
        video.read(frame);
        cv::flip(frame, frame, 1);
        //cv::filter2D(frame, frame, -1, gaussian_blur, cv::Point(-1, -1), 5.0, cv::BorderTypes::BORDER_REPLICATE);

        
        cv::imshow("Test",frame);
        
        if (cv::waitKey(1) == 'q') {
            break;
        }
        

    }

    video.release();
    cv::destroyAllWindows();

    return 0;
}