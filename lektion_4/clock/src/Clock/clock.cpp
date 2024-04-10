// User headers
#include "clock.h"
#include <math.h>
#include <array>
#include <algorithm>

Clock::Clock(float dt, int h, int w):_dt(dt)
{
  _canvas = cv::Mat(cv::Size(w, h), CV_8UC3, cv::Scalar(0, 0, 0));
}

void Clock::update(){
  // Update the angle of the clock arm, to a time step dt into the future
    _angle += (2*M_PI/60.0)*_dt;
    _angle = fmod(_angle,2*M_PI);
}

void Clock::draw(){
    cv::Mat img;
    _canvas.copyTo(img);

    int cx = _canvas.cols/2;
    int cy = _canvas.rows/2;

    // Draw clock arms
    double length = 200;
    cv::line(img, cv::Point(cx, cy), cv::Point(cx+length*cos(_angle), cy + length*sin(_angle)), cv::Scalar(255,255,255));

    // Draw clock center
    cv::circle(img, cv::Point(cx, cy), 3, cv::Scalar(0, 255, 0), -1);


    // Clock Face vars
    double faceangle = 0;
    double lineStart = length + 2;
    double lineEnd = length + 8;

    // Draw clock face
    cv::circle(img, cv::Point(cx, cy), lineEnd, cv::Scalar(255, 255, 255), 2);

    // Draw clock face lines
    while (faceangle<2*M_PI) {
        faceangle += (2*M_PI/60.0)*5;
        cv::line(img, cv::Point(cx+lineStart*cos(faceangle), cy + lineStart*sin(faceangle)), cv::Point(cx+lineEnd*cos(faceangle), cy + lineEnd*sin(faceangle)), cv::Scalar(255,255,255));
    }

    // Increment trail
    trail[1] = cv::Point(cx+length*cos(_angle), cy + length*sin(_angle));
    std::rotate(trail.rbegin(), trail.rbegin() + 1, trail.rend());

    // Draw Trail
    for (int i = 0; i < trail.size(); i++) {
        cv::circle(img, trail[i], 1 , cv::Scalar(100, 100, 255), 0);
    }


    cv::imshow("Image", img);
}

void Clock::simulate(int fps){

    while(1){

        // Compute how many updates to do pr. frame
        float updatesPerSecond = 1.0/_dt;
        float secondsPerFrame = 1.0/float(fps);
        float updatesPerFrame = updatesPerSecond*secondsPerFrame;

        // Update the clock's internal state and draw the frame
        for(int i = 0; i < updatesPerFrame; i++){
          update();
        }
        draw();

        // Wait for the next frame
        float millisecondsPerFrame = 1000.0*secondsPerFrame;
        char key = cv::waitKey(millisecondsPerFrame);
        if(key =='q'){
          break;
        }
    }
}
