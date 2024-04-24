#include <iostream>
#include <vector>


// Opencv
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

// User headers
#include "complex_number.h"
#include "mandelbrot.h"


int main(){

    ComplexNumber a(5, 2);
    a.print();
    ComplexNumber b(3,1);
    (a+b).print(); //8+3i
    (a*b).print(); //13+11i
    std::cout << a.magnitude() << std::endl; //5.38516

    //This center point provides a nice visualization
    int N = 100;
    cv::Point2f center = cv::Point2f(-0.160701788300366, 1.037566551323223);
    Mandelbrot mandelbrot(500, 2, center);
    mandelbrot.drawImageToCanvas(N);
    cv::imshow("Mandelbrot",mandelbrot.getCanvas());
    cv::waitKey(-1);//press any key to start animation
    mandelbrot.animate(0.98, N, 400);

  return 0;
}
