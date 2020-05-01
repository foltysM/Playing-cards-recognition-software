#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdlib.h>

using namespace std;
using namespace cv;

Mat original, img;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio_t = 3;
int kernel_size = 3;

void CannyThreshold(int, void*)
{
	/// Reduce noise with a kernel 3x3
	blur(img, detected_edges, Size(3, 3));

	/// Canny detector
	int ratio_sum = lowThreshold * ratio_t;
	Canny(detected_edges, detected_edges, lowThreshold, ratio_sum, kernel_size);

	/// Using Canny's output as a mask, we display our result
	dst = Scalar::all(0);

	original.copyTo(dst, detected_edges);
	namedWindow("afterCanny", WINDOW_NORMAL);
	imshow("afterCanny", dst);
}

int method1()
{
	// Reads an image
	Mat original = imread("test_red.jpg", 1);
	if (!original.data)
		return -1;

	// Downsample
	pyrDown(original, original);

	// Conversion to grayscale
	Mat img;
	cvtColor(original, img, COLOR_BGR2GRAY);
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", original);

	// Threshold
	adaptiveThreshold(img, img, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

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
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area > 2000 && area < 7500) // 3500 7500
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

int method2()
{
	// Reads an image
	original = imread("test_red.jpg", 1);
	if (!original.data)
		return -1;

	// Downsample
	pyrDown(original, original);

	dst.create(original.size(), original.type());
	
	// Conversion to grayscale
	cvtColor(original, img, COLOR_BGR2GRAY);
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", original);

	//Canny
	createTrackbar("Min Threshold:", "afterCanny", &lowThreshold, max_lowThreshold, CannyThreshold);
	CannyThreshold(0, 0);
	waitKey(0);
	return 0;
}

int method3()
{
	Mat threshed;

	original = imread("test_red.jpg", 1);
	if (!original.data)
		return -1;

	pyrDown(original, original);

	// Conversion to HSV
	cvtColor(original, img, COLOR_BGR2HSV);
	namedWindow("HSV", WINDOW_NORMAL);
	imshow("HSV", img);

	// MIN & MAX 
	int low_H = 0; // red 0  // black 0
	int low_S = 100; // red 100 // black 30
	int low_V = 0; //red 0  // black 0
	int high_H = 360/2; // red 360/2 // black 120
	int high_S = 255;  // black 255
	int high_V = 255; //black 240

	inRange(img, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), threshed);
	//cvtColor(threshed, threshedBGR, COLOR_HSV2BGR);
	
	Mat structuring_element(5, 5, CV_8U, Scalar(1));
	//morphologyEx(threshed, threshed, MORPH_ERODE, structuring_element);
	namedWindow("Method 3", WINDOW_NORMAL);
	imshow("Method 3", threshed);
	Mat threshedBGR;
	//cvtColor(threshed, threshedBGR, COLOR_HSV2BGR);
	vector<vector<Point>> contours;
	findContours(threshed, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area > 10)
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

int main()
{
	cout << "Wybierz metode wykrywania krawedzi:\n\t";
	cout << "1. Adaptive threshold --> operacje morfologiczne\n\t";
	cout << "2. Metoda Canny'ego\n\t";
	cout << "3. Konwersja do HSV i usuniecie niepotrzebnych kolorow\n\t";
	cout << "0. Wyjscie\n";

	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 0:
		return 0;
		break;
	case 1:
		if (method1() == -1)
			return -1;
		else
			return 0;
		break;

	case 2:
		if (method2() == -1)
			return -1;
		else
			return 0;
		break;

	case 3:
		if (method3() == -1)
			return -1;
		else
			return 0;
		break;

	default:
		cout << "Something went wrong";
		return -1;
		break;
	}
	
	waitKey(0);
	return 0;
}