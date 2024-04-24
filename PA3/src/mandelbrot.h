#pragma once

#include "complex_number.h"

// Opencv
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class Mandelbrot{
    private:
    int canvas_size;
    cv::Mat canvas;
    cv::Point2d center;
    double _limit;
    int iterationsToDiverge(ComplexNumber x,int N);
public:
    Mandelbrot(int canvas_size,double initial_limit,cv::Point2d center);
    cv::Mat getCanvas();
    void drawImageToCanvas(int N);
    void animate(double rate,int N,int steps);
};
