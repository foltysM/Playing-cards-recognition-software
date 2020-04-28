#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdlib.h>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("test.jpg", 0);
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	pyrDown(img, img);
	threshold(img, img, 60, 255, THRESH_BINARY); //WORKS ONLY WITH BLACK CARDS
	//adaptiveThreshold(img, img, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 101, 1);
	namedWindow("After threshold", WINDOW_NORMAL);
	imshow("After threshold", img);
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	Mat closed = img.clone();
	morphologyEx(img, closed, MORPH_CLOSE, structuring_element);
	morphologyEx(closed, img, MORPH_CLOSE, structuring_element);
	namedWindow("After morph", WINDOW_NORMAL);
	imshow("After morph", img);

	waitKey(0);
	return 0;
}