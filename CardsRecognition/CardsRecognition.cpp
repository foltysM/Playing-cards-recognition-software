﻿#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat original, img;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio_t = 3;
int kernel_size = 3;
vector<Point> pik;
vector<Point> karo;
vector<Point> trefl;
vector<Point> kier;

vector<Point> two;
vector<Point> three;
vector<Point> four;
vector<Point> five;
vector<Point> six;
vector<Point> seven;
vector<Point> eight;
vector<Point> nine;
vector<Point> ten;
vector<Point> jack;
vector<Point> queen;
vector<Point> king;
vector<Point> ace;

int findTwo()
{
	// Reads an image
	Mat twooriginal = imread("numbers/two.jpg", 1);
	if (!twooriginal.data)
		return -1;

	// Downsample
	pyrDown(twooriginal, twooriginal);

	// Conversion to grayscale
	Mat twoimg;
	cvtColor(twooriginal, twoimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(twoimg, twoimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(twoimg, twoimg, MORPH_CLOSE, structuring_element);
	morphologyEx(twoimg, twoimg, MORPH_CLOSE, structuring_element);
	morphologyEx(twoimg, twoimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(twoimg, twoimg, MORPH_DILATE, structuring_element);
	morphologyEx(twoimg, twoimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> twocontours;
	findContours(twoimg, twocontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < twocontours.size(); i++)
	{
		double area = contourArea(twocontours[i]);
		if (area > 1000) // 3500 7500
		{
			drawContours(twooriginal, twocontours, i, Scalar(0, 255, 0), 4, 8);
			two = twocontours[i];
			count++;
		}
	}
	//namedWindow("two", WINDOW_NORMAL);
	//imshow("two", twooriginal);
	return 0;
}

int findThree()
{
	// Reads an image
	Mat threeoriginal = imread("numbers/three.jpg", 1);
	if (!threeoriginal.data)
		return -1;

	// Downsample
	pyrDown(threeoriginal, threeoriginal);

	// Conversion to grayscale
	Mat threeimg;
	cvtColor(threeoriginal, threeimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(threeimg, threeimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(threeimg, threeimg, MORPH_CLOSE, structuring_element);
	morphologyEx(threeimg, threeimg, MORPH_CLOSE, structuring_element);
	morphologyEx(threeimg, threeimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(threeimg, threeimg, MORPH_DILATE, structuring_element);
	morphologyEx(threeimg, threeimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> threecontours;
	findContours(threeimg, threecontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < threecontours.size(); i++)
	{
		double area = contourArea(threecontours[i]);
		if (area > 1000) // 3500 7500
		{
			drawContours(threeoriginal, threecontours, i, Scalar(0, 255, 0), 4, 8);
			three = threecontours[i];
			count++;
		}
	}
	//namedWindow("three", WINDOW_NORMAL);
	//imshow("three", threeoriginal);
	return 0;
}

int findFour()
{
	// Reads an image
	Mat fouroriginal = imread("numbers/four.jpg", 1);
	if (!fouroriginal.data)
		return -1;

	// Downsample
	pyrDown(fouroriginal, fouroriginal);

	// Conversion to grayscale
	Mat fourimg;
	cvtColor(fouroriginal, fourimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(fourimg, fourimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(fourimg, fourimg, MORPH_CLOSE, structuring_element);
	morphologyEx(fourimg, fourimg, MORPH_CLOSE, structuring_element);
	morphologyEx(fourimg, fourimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(fourimg, fourimg, MORPH_DILATE, structuring_element);
	morphologyEx(fourimg, fourimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> fourcontours;
	findContours(fourimg, fourcontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < fourcontours.size(); i++)
	{
		double area = contourArea(fourcontours[i]);
		if (area > 8000) // 3500 7500
		{
			drawContours(fouroriginal, fourcontours, i, Scalar(0, 255, 0), 4, 8);
			four = fourcontours[i];
			count++;
		}
	}
	//namedWindow("four", WINDOW_NORMAL);
	//imshow("four", fouroriginal);
	return 0;
}

int findFive()
{
	// Reads an image
	Mat fiveoriginal = imread("numbers/five.jpg", 1);
	if (!fiveoriginal.data)
		return -1;

	// Downsample
	pyrDown(fiveoriginal, fiveoriginal);

	// Conversion to grayscale
	Mat fiveimg;
	cvtColor(fiveoriginal, fiveimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(fiveimg, fiveimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(fiveimg, fiveimg, MORPH_CLOSE, structuring_element);
	morphologyEx(fiveimg, fiveimg, MORPH_CLOSE, structuring_element);
	morphologyEx(fiveimg, fiveimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(fiveimg, fiveimg, MORPH_DILATE, structuring_element);
	morphologyEx(fiveimg, fiveimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> fivecontours;
	findContours(fiveimg, fivecontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < fivecontours.size(); i++)
	{
		double area = contourArea(fivecontours[i]);
		if (area > 1000) // 3500 7500
		{
			drawContours(fiveoriginal, fivecontours, i, Scalar(0, 255, 0), 4, 8);
			five = fivecontours[i];
			count++;
		}
	}
	//namedWindow("five", WINDOW_NORMAL);
	//imshow("five", fiveoriginal);
	return 0;
}

int findSix()
{
	// Reads an image
	Mat sixoriginal = imread("numbers/six.jpg", 1);
	if (!sixoriginal.data)
		return -1;

	// Downsample
	pyrDown(sixoriginal, sixoriginal);

	// Conversion to grayscale
	Mat siximg;
	cvtColor(sixoriginal, siximg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(siximg, siximg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(siximg, siximg, MORPH_CLOSE, structuring_element);
	morphologyEx(siximg, siximg, MORPH_CLOSE, structuring_element);
	morphologyEx(siximg, siximg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(siximg, siximg, MORPH_DILATE, structuring_element);
	morphologyEx(siximg, siximg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> sixcontours;
	findContours(siximg, sixcontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < sixcontours.size(); i++)
	{
		double area = contourArea(sixcontours[i]);
		if (area > 8000) // 3500 7500
		{
			drawContours(sixoriginal, sixcontours, i, Scalar(0, 255, 0), 4, 8);
			six = sixcontours[i];
			count++;
		}
	}
	//namedWindow("six", WINDOW_NORMAL);
	//imshow("six", sixoriginal);
	return 0;
}

int findSeven()
{
	// Reads an image
	Mat sevenoriginal = imread("numbers/seven.jpg", 1);
	if (!sevenoriginal.data)
		return -1;

	// Downsample
	pyrDown(sevenoriginal, sevenoriginal);

	// Conversion to grayscale
	Mat sevenimg;
	cvtColor(sevenoriginal, sevenimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(sevenimg, sevenimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(sevenimg, sevenimg, MORPH_CLOSE, structuring_element);
	morphologyEx(sevenimg, sevenimg, MORPH_CLOSE, structuring_element);
	morphologyEx(sevenimg, sevenimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(sevenimg, sevenimg, MORPH_DILATE, structuring_element);
	morphologyEx(sevenimg, sevenimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> sevencontours;
	findContours(sevenimg, sevencontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < sevencontours.size(); i++)
	{
		double area = contourArea(sevencontours[i]);
		if (area > 2000 && area < 7500) // 3500 7500
		{
			drawContours(sevenoriginal, sevencontours, i, Scalar(0, 255, 0), 4, 8);
			seven = sevencontours[i];
			count++;
		}
	}
	//namedWindow("seven", WINDOW_NORMAL);
	//imshow("seven", sevenoriginal);
	return 0;
}

int findEight()
{
	// Reads an image
	Mat eightoriginal = imread("numbers/eight.jpg", 1);
	if (!eightoriginal.data)
		return -1;

	// Downsample
	pyrDown(eightoriginal, eightoriginal);

	// Conversion to grayscale
	Mat eightimg;
	cvtColor(eightoriginal, eightimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(eightimg, eightimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(eightimg, eightimg, MORPH_CLOSE, structuring_element);
	morphologyEx(eightimg, eightimg, MORPH_CLOSE, structuring_element);
	morphologyEx(eightimg, eightimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(eightimg, eightimg, MORPH_DILATE, structuring_element);
	morphologyEx(eightimg, eightimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> eightcontours;
	findContours(eightimg, eightcontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < eightcontours.size(); i++)
	{
		double area = contourArea(eightcontours[i]);
		if (area > 8000) // 3500 7500
		{
			drawContours(eightoriginal, eightcontours, i, Scalar(0, 255, 0), 4, 8);
			eight = eightcontours[i];
			count++;
		}
	}
	//namedWindow("eight", WINDOW_NORMAL);
	//imshow("eight", eightoriginal);
	return 0;
}

int findNine()
{
	// Reads an image
	Mat nineoriginal = imread("numbers/nine.jpg", 1);
	if (!nineoriginal.data)
		return -1;

	// Downsample
	pyrDown(nineoriginal, nineoriginal);

	// Conversion to grayscale
	Mat nineimg;
	cvtColor(nineoriginal, nineimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(nineimg, nineimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(nineimg, nineimg, MORPH_CLOSE, structuring_element);
	morphologyEx(nineimg, nineimg, MORPH_CLOSE, structuring_element);
	morphologyEx(nineimg, nineimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(nineimg, nineimg, MORPH_DILATE, structuring_element);
	morphologyEx(nineimg, nineimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> ninecontours;
	findContours(nineimg, ninecontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < ninecontours.size(); i++)
	{
		double area = contourArea(ninecontours[i]);
		if (area > 8000) // 3500 7500
		{
			drawContours(nineoriginal, ninecontours, i, Scalar(0, 255, 0), 4, 8);
			nine = ninecontours[i];
			count++;
		}
	}
	//namedWindow("nine", WINDOW_NORMAL);
	//imshow("nine", nineoriginal);
	return 0;
}

int findTen()
{
	// Reads an image
	Mat tenoriginal = imread("numbers/one.jpg", 1);
	if (!tenoriginal.data)
		return -1;

	// Downsample
	pyrDown(tenoriginal, tenoriginal);

	// Conversion to grayscale
	Mat tenimg;
	cvtColor(tenoriginal, tenimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(tenimg, tenimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(tenimg, tenimg, MORPH_CLOSE, structuring_element);
	morphologyEx(tenimg, tenimg, MORPH_CLOSE, structuring_element);
	morphologyEx(tenimg, tenimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(tenimg, tenimg, MORPH_DILATE, structuring_element);
	morphologyEx(tenimg, tenimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> tencontours;
	findContours(tenimg, tencontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < tencontours.size(); i++)
	{
		double area = contourArea(tencontours[i]);
		if (area > 2000 && area < 7500) // 3500 7500
		{
			drawContours(tenoriginal, tencontours, i, Scalar(0, 255, 0), 4, 8);
			ten = tencontours[i];
			count++;
		}
	}
	//namedWindow("ten", WINDOW_NORMAL);
	//imshow("ten", tenoriginal);
	return 0;
}

int findJack()
{
	// Reads an image
	Mat jackoriginal = imread("numbers/jack.jpg", 1);
	if (!jackoriginal.data)
		return -1;

	// Downsample
	pyrDown(jackoriginal, jackoriginal);

	// Conversion to grayscale
	Mat jackimg;
	cvtColor(jackoriginal, jackimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(jackimg, jackimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(jackimg, jackimg, MORPH_CLOSE, structuring_element);
	morphologyEx(jackimg, jackimg, MORPH_CLOSE, structuring_element);
	morphologyEx(jackimg, jackimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(jackimg, jackimg, MORPH_DILATE, structuring_element);
	morphologyEx(jackimg, jackimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> jackcontours;
	findContours(jackimg, jackcontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < jackcontours.size(); i++)
	{
		double area = contourArea(jackcontours[i]);
		if (area > 2000 && area < 7500) // 3500 7500
		{
			drawContours(jackoriginal, jackcontours, i, Scalar(0, 255, 0), 4, 8);
			jack = jackcontours[i];
			count++;
		}
	}
	//namedWindow("jack", WINDOW_NORMAL);
	//imshow("jack", jackoriginal);
	return 0;
}

int findQueen()
{
	// Reads an image
	Mat queenoriginal = imread("numbers/queen.jpg", 1);
	if (!queenoriginal.data)
		return -1;

	// Downsample
	pyrDown(queenoriginal, queenoriginal);

	// Conversion to grayscale
	Mat queenimg;
	cvtColor(queenoriginal, queenimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(queenimg, queenimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(queenimg, queenimg, MORPH_CLOSE, structuring_element);
	morphologyEx(queenimg, queenimg, MORPH_CLOSE, structuring_element);
	morphologyEx(queenimg, queenimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(queenimg, queenimg, MORPH_DILATE, structuring_element);
	morphologyEx(queenimg, queenimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> queencontours;
	findContours(queenimg, queencontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < queencontours.size(); i++)
	{
		double area = contourArea(queencontours[i]);
		if (area > 10000) // 3500 7500
		{
			drawContours(queenoriginal, queencontours, i, Scalar(0, 255, 0), 4, 8);
			queen = queencontours[i];
			count++;
		}
	}
	//namedWindow("queen", WINDOW_NORMAL);
	//imshow("queen", queenoriginal);
	return 0;
}

int findKing()
{
	// Reads an image
	Mat kingoriginal = imread("numbers/king.jpg", 1);
	if (!kingoriginal.data)
		return -1;

	// Downsample
	pyrDown(kingoriginal, kingoriginal);

	// Conversion to grayscale
	Mat kingimg;
	cvtColor(kingoriginal, kingimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(kingimg, kingimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(kingimg, kingimg, MORPH_CLOSE, structuring_element);
	morphologyEx(kingimg, kingimg, MORPH_CLOSE, structuring_element);
	morphologyEx(kingimg, kingimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(kingimg, kingimg, MORPH_DILATE, structuring_element);
	morphologyEx(kingimg, kingimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> kingcontours;
	findContours(kingimg, kingcontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < kingcontours.size(); i++)
	{
		double area = contourArea(kingcontours[i]);
		if (area > 1000) // 3500 7500
		{
			drawContours(kingoriginal, kingcontours, i, Scalar(0, 255, 0), 4, 8);
			king = kingcontours[i];
			count++;
		}
	}
	//namedWindow("king", WINDOW_NORMAL);
	//imshow("king", kingoriginal);
	return 0;
}

int findAce()
{
	// Reads an image
	Mat aceoriginal = imread("numbers/ace.jpg", 1);
	if (!aceoriginal.data)
		return -1;

	// Downsample
	pyrDown(aceoriginal, aceoriginal);

	// Conversion to grayscale
	Mat aceimg;
	cvtColor(aceoriginal, aceimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(aceimg, aceimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(aceimg, aceimg, MORPH_CLOSE, structuring_element);
	morphologyEx(aceimg, aceimg, MORPH_CLOSE, structuring_element);
	morphologyEx(aceimg, aceimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(aceimg, aceimg, MORPH_DILATE, structuring_element);
	morphologyEx(aceimg, aceimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> acecontours;
	findContours(aceimg, acecontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < acecontours.size(); i++)
	{
		double area = contourArea(acecontours[i]);
		if (area > 7000) // 3500 7500
		{
			drawContours(aceoriginal, acecontours, i, Scalar(0, 255, 0), 4, 8);
			ace = acecontours[i];
			count++;
		}
	}
	//namedWindow("ace", WINDOW_NORMAL);
	//imshow("ace", aceoriginal);
	waitKey(0);
	return 0;
}

int findTrefl()
{
	// Reads an image
	Mat trefloriginal = imread("trefl.jpg", 1);
	if (!trefloriginal.data)
		return -1;

	// Downsample
	pyrDown(trefloriginal, trefloriginal);

	// Conversion to grayscale
	Mat treflimg;
	cvtColor(trefloriginal, treflimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(treflimg, treflimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(treflimg, treflimg, MORPH_CLOSE, structuring_element);
	morphologyEx(treflimg, treflimg, MORPH_CLOSE, structuring_element);
	morphologyEx(treflimg, treflimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(treflimg, treflimg, MORPH_DILATE, structuring_element);
	morphologyEx(treflimg, treflimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> treflcontours;
	findContours(treflimg, treflcontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < treflcontours.size(); i++)
	{
		double area = contourArea(treflcontours[i]);
		if (area > 2000 && area < 7500) // 3500 7500
		{
			drawContours(trefloriginal, treflcontours, i, Scalar(0, 255, 0), 4, 8);
			trefl = treflcontours[i];
			count++;
		}
	}
	//namedWindow("trefl", WINDOW_NORMAL);
	//imshow("trefl", trefloriginal);
	return 0;
}

int findKaro()
{
	// Reads an image
	Mat karooriginal = imread("karo.jpg", 1);
	if (!karooriginal.data)
		return -1;

	// Downsample
	pyrDown(karooriginal, karooriginal);

	// Conversion to grayscale
	Mat karoimg;
	cvtColor(karooriginal, karoimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(karoimg, karoimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(karoimg, karoimg, MORPH_CLOSE, structuring_element);
	morphologyEx(karoimg, karoimg, MORPH_CLOSE, structuring_element);
	morphologyEx(karoimg, karoimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(karoimg, karoimg, MORPH_DILATE, structuring_element);
	morphologyEx(karoimg, karoimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> karocontours;
	findContours(karoimg, karocontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < karocontours.size(); i++)
	{
		double area = contourArea(karocontours[i]);
		if (area > 2000 && area < 7500) // 3500 7500
		{
			drawContours(karooriginal, karocontours, i, Scalar(0, 255, 0), 4, 8);
			karo = karocontours[i];
			count++;
		}
	}
	//namedWindow("karo", WINDOW_NORMAL);
	//imshow("karo", karooriginal);
	return 0;
}

int findKier()
{
	// Reads an image
	Mat kieroriginal = imread("kier.jpg", 1);
	if (!kieroriginal.data)
		return -1;

	// Downsample
	pyrDown(kieroriginal, kieroriginal);

	// Conversion to grayscale
	Mat kierimg;
	cvtColor(kieroriginal, kierimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(kierimg, kierimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(kierimg, kierimg, MORPH_CLOSE, structuring_element);
	morphologyEx(kierimg, kierimg, MORPH_CLOSE, structuring_element);
	morphologyEx(kierimg, kierimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(kierimg, kierimg, MORPH_DILATE, structuring_element);
	morphologyEx(kierimg, kierimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> kiercontours;
	findContours(kierimg, kiercontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < kiercontours.size(); i++)
	{
		double area = contourArea(kiercontours[i]);
		if (area > 250) // 3500 7500
		{
			drawContours(kieroriginal, kiercontours, i, Scalar(0, 255, 0), 4, 8);
			kier = kiercontours[i];
			count++;
		}
	}
	//namedWindow("kier", WINDOW_NORMAL);
	//imshow("kier", kieroriginal);
	return 0;
}

int findPik()
{
	// Reads an image
	Mat pikoriginal = imread("pik.jpg", 1);
	if (!pikoriginal.data)
		return -1;

	// Downsample
	pyrDown(pikoriginal, pikoriginal);

	// Conversion to grayscale
	Mat pikimg;
	cvtColor(pikoriginal, pikimg, COLOR_BGR2GRAY);

	// Threshold
	adaptiveThreshold(pikimg, pikimg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 101, 1);

	// Morphology
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(pikimg, pikimg, MORPH_CLOSE, structuring_element);
	morphologyEx(pikimg, pikimg, MORPH_CLOSE, structuring_element);
	morphologyEx(pikimg, pikimg, MORPH_OPEN, structuring_element);
	Mat structuring_element2(5, 5, CV_8U, Scalar(1));
	morphologyEx(pikimg, pikimg, MORPH_DILATE, structuring_element);
	morphologyEx(pikimg, pikimg, MORPH_ERODE, structuring_element2);

	// Contours
	vector<vector<Point>> pikcontours;
	findContours(pikimg, pikcontours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int count = 0;
	for (int i = 0; i < pikcontours.size(); i++)
	{
		double area = contourArea(pikcontours[i]);
		if (area > 2000 && area < 7500) // 3500 7500
		{
			drawContours(pikoriginal, pikcontours, i, Scalar(0, 255, 0), 4, 8);
			pik = pikcontours[i];
			count++;
		}
	}
	//namedWindow("pik", WINDOW_NORMAL);
	//imshow("pik", pikoriginal);	
	return 0;
}

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
	Mat original = imread("three_kier.jpg", 1);
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
	//namedWindow("After morph", WINDOW_NORMAL);
	//imshow("After morph", img);

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
	
	for (int i = 0; i < contours.size(); i++)
	{
		double a, b, c;
		//PIK
		a = matchShapes(pik, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(pik, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.05 && a < 0.045)
			cout << "PIK " << i << " " << a<<" "<<b << endl;
		//TREFL
		a = matchShapes(trefl, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(trefl, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.05 && a < 0.045)
			cout << "TREFL " << i << " " << a << " " << b << endl;
		//KARO
		a = matchShapes(karo, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(karo, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.03 && a < 0.025)
			cout << "KARO " << i << " " << a << " " << b << endl;
		//KIER
		a = matchShapes(kier, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(kier, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "KIER " << i << " " << a << " " << b << endl;
		//TWO
		a = matchShapes(two, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(two, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(two, contours[i], CONTOURS_MATCH_I2, 0);
		if ( a < 0.8 && b < 0.35) // 0,055 0,05
			cout << "TWO " << i << " " << a << " " << b << " "<<c<< endl;
		
		//THREE
		a = matchShapes(three, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(three, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.05 && a < 0.045)
			cout << "THREE " << i << " " << a << " " << b << endl;
		//FOUR
		a = matchShapes(four, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(four, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "FOUR " << i << " " << a << " " << b << endl;
		//FIVE
		a = matchShapes(five, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(five, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "FIVE " << i << " " << a << " " << b << endl;
		//SIX
		a = matchShapes(six, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(six, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "SIX " << i << " " << a << " " << b << endl;
		//SEVEN
		a = matchShapes(seven, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(seven, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "SEVEN " << i << " " << a << " " << b << endl;
		//EIGHT
		a = matchShapes(eight, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(eight, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(eight, contours[i], CONTOURS_MATCH_I2, 0);
		if ((b < 0.02 && a < 0.01)||c<0.02)
			cout << "EIGHT " << i << " " << a << " " << b << " "<<c<<endl;

		//NINE
		a = matchShapes(nine, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(nine, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "NINE " << i << " " << a << " " << b << endl;
		//TEN
		a = matchShapes(ten, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(ten, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "TEN " << i << " " << a << " " << b << endl;
		//JACK
		a = matchShapes(jack, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(jack, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "JACK " << i << " " << a << " " << b << endl;
		//QUEEN
		a = matchShapes(queen, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(queen, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(queen, contours[i], CONTOURS_MATCH_I2, 0);
		if (b < 0.01 && a < 0.015)
			cout << "QUEEN " << i << " " << a << " " << b << " " <<c<< endl;
		//KING
		a = matchShapes(king, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(king, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "KING " << i << " " << a << " " << b << endl;
		//ACE
		a = matchShapes(ace, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(ace, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.025 && a < 0.025)
			cout << "ACE " << i << " " << a << " " << b << endl;


	}
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
	if (findPik() == -1)
		return -1;

	if (findKier() == -1)
		return -1;
	
	if (findKaro() == -1)
		return -1;
	
	if (findTrefl() == -1)
		return -1;
	
	if (findTwo() == -1)
		return -1;

	if (findThree() == -1)
		return -1;

	if (findFour() == -1)
		return -1;

	if (findFive() == -1)
		return -1;

	if (findSix() == -1)
		return -1;

	if (findSeven() == -1)
		return -1;

	if (findEight() == -1)
		return -1;

	if (findNine() == -1)
		return -1;

	if (findTen() == -1)
		return -1;

	if (findJack() == -1)
		return -1;

	if (findQueen() == -1)
		return -1;

	if (findKing() == -1)
		return -1;

	if (findAce() == -1)
		return -1;

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
	cout << "end" << endl;

	waitKey(0);
	return 0;
}