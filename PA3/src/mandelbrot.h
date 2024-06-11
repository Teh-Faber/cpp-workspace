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
    int _canvas_size;
    cv::Mat _canvas;
    cv::Point2d _center;
    double _limit;

    int iterationsToDiverge(ComplexNumber x, int N){
        ComplexNumber z = ComplexNumber(0,0); // z_0
        int i = 0;
        int maxIterations = 50;


        for(; z.magnitude() < 2; i++){ // magnitude > 2 means complex sequnce diverges

            z = z*z + x;   // complex sequence z_n+1 = (z_n)² + c

            if(i >= maxIterations) return N; // if maxIterations is reached
        }

        return i;
    }

public:
    Mandelbrot(int canvas_size, double initial_limit, cv::Point2d center): _canvas_size(canvas_size), _limit(initial_limit), _center(center){
        _canvas = cv::Mat(_canvas_size, _canvas_size, CV_8UC1); // construct matrix of pixel values
    }

    cv::Mat getCanvas(){
        return _canvas;
    }

    void drawImageToCanvas(int N){
        double step = _limit/_canvas_size; // change in unit(i.e re & im) per pixel
        double re;
        double im;
        int iter;

        for(int c = 0; c <= _canvas.cols; ++c){ // for every col in img
            for(int r = 0; r <= _canvas.rows; ++r){ // for every row in img
                // calculate current pixel as a complex number
                re = _center.x - _limit/2 * c * step;
                im = _center.y - _limit/2 * r * step;
                // iterationsToDiverge determines pixel value
                iter = iterationsToDiverge(ComplexNumber(re, im), N);
                // insert pixel value
                _canvas.at<uchar>(cv::Point(c,r)) = 255*iter/N;
            }
        }
    }

    void animate(double rate,int N,int steps){
        for(int i = 0; i < steps; ++i){
            drawImageToCanvas(N); // update pixels
            cv::imshow("Mandelbrot",_canvas); // show new frame
            _limit *= rate; // update img borders aka limits

            char c = cv::waitKey(1); // quit if q is pressed
            if(c=='q') break;
        }
    }
};
