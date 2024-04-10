// stdlib
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>

// Opencv
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class Clock{
  cv::Mat _canvas;
  double _angle = 0;
  double _dt;

  // Clock Face vars
  std::array <cv::Point, 60*5> trail;

public:
  Clock(float dt, int h, int w);
  void update();
  void draw();
  void simulate(int fps);
};

