#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main() {
    std::string imgPath = cv::samples::findFile("opencv_logo.png");
    std::cout << "Trying to display : " << imgPath << std::endl;
    cv::Mat src = cv::imread(imgPath, cv::IMREAD_COLOR);
    cv::imshow("Here is my image",src);
    cv::waitKey(0);
}
