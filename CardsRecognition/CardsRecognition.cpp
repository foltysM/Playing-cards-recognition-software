#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdlib.h>

using namespace std;
using namespace cv;

int main()
{
	// Reads an image
	Mat original = imread("test_red.jpg", 1);
	
	// Downsample
	pyrDown(original, original);
	
	// Conversion to grayscale
	Mat img;
	cvtColor(original, img, COLOR_BGR2GRAY);
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", original);
	
	// Threshold
	//threshold(img, img, 60, 255, THRESH_BINARY); //WORKS ONLY WITH BLACK CARDS
	adaptiveThreshold(img, img, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);
// 	namedWindow("After threshold", WINDOW_NORMAL);
// 	imshow("After threshold", img);
 	
	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(img, img, MORPH_CLOSE, structuring_element);
	morphologyEx(img, img, MORPH_CLOSE, structuring_element);
	morphologyEx(img, img, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(img, img, MORPH_DILATE, structuring_element);
	morphologyEx(img, img, MORPH_ERODE, structuring_element2);
	namedWindow("After morph", WINDOW_NORMAL);
	imshow("After morph", img);

	// Contours
	vector<vector<Point>> contours;
	findContours(img, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i<contours.size(); i++) 
	{
		double area = contourArea(contours[i]);
		if (area > 2000 && area <7500) // 3500 7500
		{
			drawContours(original, contours, i, Scalar(0, 255, 0), 4, 8);
			count++;
		}
	}
	namedWindow("After contours", WINDOW_NORMAL);
	imshow("After contours", original);
	
	waitKey(0);
	return 0;
}