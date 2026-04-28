#include <iostream>
#include <string>
#include<opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "include/morphology.hpp"


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
    
    cv::namedWindow("FinalColor",cv::WINDOW_NORMAL);
    cv::resizeWindow("FinalColor",800,600);

    //sliders
    cv::namedWindow("Sliders",cv::WINDOW_GUI_NORMAL);
    cv::resizeWindow("Sliders", 300,300);
    cv::createTrackbar("Hue Min", "Sliders",&hmin,179);
    cv::createTrackbar("Hue Max", "Sliders",&hmax,179);
    cv::createTrackbar("Saturation Min", "Sliders",&smin,255);
    cv::createTrackbar("Saturation Max", "Sliders",&smax,255);
    cv::createTrackbar("Value Min", "Sliders",&vmin,255);
    cv::createTrackbar("Value Max", "Sliders",&vmax,255);
   /*
    cv::createTrackbar("Hue Min", "DEBUG",&hmin,179);
    cv::createTrackbar("Hue Max", "DEBUG",&hmax,179);
    cv::createTrackbar("Saturation Min", "DEBUG",&smin,255);
    cv::createTrackbar("Saturation Max", "DEBUG",&smax,255);
    cv::createTrackbar("Value Min", "DEBUG",&vmin,255);
    cv::createTrackbar("Value Max", "DEBUG",&vmax,255);
    */
    cv::namedWindow("Morphologytest",cv::WINDOW_NORMAL);
    cv::resizeWindow("Morphologytest",800,600);
    
    while (video.isOpened()){
       
        video.read(frame);

        
        cv::flip(frame, frame, 1);
        cv::Mat matDebug = frame.clone();
        cv::Scalar lim_lower(hmin, smin, vmin);
        cv::Scalar lim_upper(hmax, smax, vmax);
        cv::Mat ColoredObj;

        cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);   //Changing the colorspace from BGR to HSV

        cv::inRange(frame, lim_lower, lim_upper, mask);

        cv::Mat temp1{mask.size(),mask.type()};
        cv::Mat OutputframeOpening{mask.size(),mask.type()};
        cv::Mat OutputframeClosing{mask.size(),mask.type()};

        int kernel_size = 5;
        //temp1 = erosion(mask,temp1,kernel_size);
        //OutputframeOpening = dilation(temp1,OutputframeOpening,kernel_size);
        temp1 = dilation(mask,temp1,kernel_size);
        OutputframeClosing = erosion(temp1,OutputframeClosing,kernel_size);
        temp1 = dilation(OutputframeClosing,temp1,kernel_size);
        OutputframeClosing = erosion(temp1,OutputframeClosing,kernel_size);

        cv::bitwise_and(matDebug,matDebug,ColoredObj,OutputframeClosing);


        //===============contours====================
        std::vector<std::vector<cv::Point>> contours;
        std::vector<cv::Vec4i> hierarchy;
        cv::findContours(OutputframeClosing,contours, hierarchy,cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

            for(size_t i = 0; i < contours.size(); i++){
                double area = cv::contourArea(contours[i]);

                if(area >250){
                    cv::drawContours(ColoredObj, contours, -1, cv::Scalar(0,255,0),2);
                    cv::drawContours(matDebug, contours, -1, cv::Scalar(0,255,0),2);
                }       

 
            }
        




        cv::imshow("DEBUG",matDebug);
        cv::imshow("OCIRO",mask);
        cv::imshow("Morphologytest", OutputframeClosing);
        cv::imshow("FinalColor",ColoredObj);

            if (cv::waitKey(1) == 'q') {
                break;
            }
    }

    video.release();
    cv::destroyAllWindows();

    return 0;
}



