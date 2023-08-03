// OpenCVPractice.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <chrono>
#include <string>

using namespace std;

int main()
{
	const string imagePath = "/home/chacha/distorted.png";

	double k1 = -0.28340811;
	double k2 = 0.07395907;
	double p1 = 0.00019359;
	double p2 = 1.76187114e-05;

	double fx = 458.654;
	double fy = 457.296;
	double cx = 367.215;
	double cy = 248.375;

	cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);

	cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
	cv::imshow("Original", image);

	cout << "Hello CMake." << endl;
	return 0;
}
