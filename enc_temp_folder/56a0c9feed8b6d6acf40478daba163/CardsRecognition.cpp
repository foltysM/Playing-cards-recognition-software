#include <iostream>
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
	namedWindow("trefl", WINDOW_NORMAL);
	imshow("trefl", trefloriginal);
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
	namedWindow("karo", WINDOW_NORMAL);
	imshow("karo", karooriginal);
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
	namedWindow("kier", WINDOW_NORMAL);
	imshow("kier", kieroriginal);
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
	namedWindow("pik", WINDOW_NORMAL);
	imshow("pik", pikoriginal);	
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
	Mat original = imread("test_trefl.jpg", 1);
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
	


	// DO PRZERZUCENIA GDZIE INDZIEJ <---------------------------------------------------------------------------------------
	for (int i = 0; i < contours.size(); i++)
	{
		double a, b;
		//PIK
		a = matchShapes(pik, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(pik, contours[i], CONTOURS_MATCH_I3, 0);
		if (b < 0.03 && a < 0.025)
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