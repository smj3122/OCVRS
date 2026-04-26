#include <iostream>
#include <string>
#include<opencv2/opencv.hpp>


int main (){
    cv::VideoCapture video(0, cv::CAP_V4L2);   //Getting input from camera
    cv::Mat frame;                              //creating a matrix object to contain camera input
    cv::Mat mask;



    int hmin = 0, smin = 75, vmin = 0;
    int hmax = 5, smax = 255, vmax = 255;




    //Create a window
    cv::namedWindow("OCIRO", cv::WINDOW_NORMAL);
    cv::resizeWindow("OCIRO", 800,600);


    cv::namedWindow("DEBUG", cv::WINDOW_NORMAL);
    cv::resizeWindow("DEBUG", 866, 600);

    //sliders
    /* Instead of creating a new window sliders Updated the DEBUG WINDOW to have the sliders
    cv::namedWindow("Sliders",cv::WINDOW_GUI_NORMAL);
    cv::resizeWindow("Sliders", 200,200);
    cv::createTrackbar("Hue Min", "Sliders",&hmin,179);
    cv::createTrackbar("Hue Max", "Sliders",&hmax,179);
    cv::createTrackbar("Saturation Min", "Sliders",&smin,255);
    cv::createTrackbar("Saturation Max", "Sliders",&smax,255);
    cv::createTrackbar("Value Min", "Sliders",&vmin,255);
    cv::createTrackbar("Value Max", "Sliders",&vmax,255);
    */
    cv::createTrackbar("Hue Min", "DEBUG",&hmin,179);
    cv::createTrackbar("Hue Max", "DEBUG",&hmax,179);
    cv::createTrackbar("Saturation Min", "DEBUG",&smin,255);
    cv::createTrackbar("Saturation Max", "DEBUG",&smax,255);
    cv::createTrackbar("Value Min", "DEBUG",&vmin,255);
    cv::createTrackbar("Value Max", "DEBUG",&vmax,255);


    while (video.isOpened()){
       
        video.read(frame);

        
        cv::flip(frame, frame, 1);
        cv::Mat matDebug = frame.clone();

        cv::Scalar lim_lower(hmin, smin, vmin);
        cv::Scalar lim_upper(hmax, smax, vmax);

        cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);   //Changing the colorspace from BGR to HSV

        cv::inRange(frame, lim_lower, lim_upper, mask);


        cv::imshow("DEBUG",matDebug);
        cv::imshow("OCIRO",mask);

            if (cv::waitKey(1) == 'q') {
                break;
            }
    }

    video.release();
    cv::destroyAllWindows();

    return 0;
}