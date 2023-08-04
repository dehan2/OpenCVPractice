// OpenCVPractice.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
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

	cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);

	int rows = image.rows;
	int cols = image.cols;
	cv::Mat restoredImage = cv::Mat::zeros(rows, cols, CV_8UC1);

	for (int v = 0; v < rows; v++)
	{
		for (int u = 0; u < cols; u++)
		{
			double x = (u-cx)/fx;
			double y = (v-cy)/fy;
			double r = sqrt(x*x + y*y);
			double xDistorted = x*(1+k1*r*r+k2*r*r*r*r) + 2*p1*x*y + p2*(r*r + 2*x*x);
			double yDistorted = y*(1+k1*r*r+k2*r*r*r*r) + p1*(r*r + 2*y*y) + 2*p2*x*y;
			double uDistorted = fx*xDistorted + cx;
			double vDistorted = fy*yDistorted + cy;

			if (uDistorted >= 0 && vDistorted >= 0 && uDistorted < cols && vDistorted < rows)
			{
				restoredImage.at<uchar>(v, u) = image.at<uchar>(vDistorted, uDistorted);
			}
			else
			{
				restoredImage.at<uchar>(v, u) = 0;
			}
		}
	}

	cv::imshow("Original", image);
	cv::imshow("Restored", restoredImage);

	// wait for key stroke
	cv::waitKey(0);
	


	cout << "Hello CMake." << endl;
	return 0;
}
