#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat src, src_gray;
Mat original, img;
Mat dst, detected_edges;
int edgeThresh = 1;
unsigned int lowThreshold = 70;
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

Mat fillRectangle(vector<vector<Point>> contours_input, Mat image)
{
	int imax = 0;
	double areamax = 0;
	for (int i = 0; i < contours_input.size(); i++)
	{
		RotatedRect rect = minAreaRect(contours_input[i]);
		double width = rect.size.width;
		double height = rect.size.height;
		double area = width * height;
		if (area > 1 && area > areamax)
		{
			areamax = area;
			imax = i;
		}

	}
	//cout << "areamax " << areamax << endl;
	//cout << "i " << imax << endl;
	//cout << "END" << endl;
	int imax2 = 0;
	double areamax2 = 0;
	for (int i = 0; i < contours_input.size(); i++)
	{
		RotatedRect rect = minAreaRect(contours_input[i]);
		double width = rect.size.width;
		double height = rect.size.height;
		double area = abs(width) * abs(height);
		if (area > 1 && area > areamax2  && area<areamax && i!=imax && area<250000)
		{
			areamax2 = area;
			imax2 = i;
		}
	}
	//cout << "areamax2 " << areamax2 << endl;
	//cout << "i2 " << imax2 << endl;
	//cout << "END" << endl;

	int s = contours_input[imax2].size();
	//	Point points[1][s];

	Point** points;
	int w = 1;
	points = new Point * [w];
	
	for (int i = 0; i < w; i++)
	{
		points[i] = new Point[s];
	}
	for (int i = 0; i < s; i++)
	{
		points[0][i] = contours_input[imax2][i];
	}

	const Point* ppt[1] = { points[0] };

	int npt[] = { s };
	int lineType = LINE_8;
	fillPoly(image, ppt, npt, 1, Scalar(255, 255, 255), lineType);
	//namedWindow("Filled image", WINDOW_NORMAL);
	//imshow("Filled image", image);

	for (int i = 0; i < w; i++)
	{
		delete[] points[i];
	}
	return image;
}


bool isRed(Mat image)
{
	bool red = false;
	Mat image_HSV;
	Mat1b mask1, mask2;
	cvtColor(image, image_HSV, COLOR_BGR2HSV);
	inRange(image_HSV, Scalar(0, 70, 50), Scalar(10, 255, 255), mask1);
	inRange(image_HSV, Scalar(170, 70, 50), Scalar(180, 255, 255), mask2);

	Mat1b mask = mask1 | mask2;

	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(mask, mask, MORPH_ERODE, structuring_element);
	
	vector<vector<Point>> contours_red;
	findContours(mask, contours_red, RETR_LIST, CHAIN_APPROX_SIMPLE);

	int count = 0;
	for (int i = 0; i < contours_red.size(); i++)
	{
		double area = contourArea(contours_red[i]);
		if (area > 200)
		{
			drawContours(image, contours_red, i, Scalar(0, 255, 0), 4, 8);
			red = true;
			count++;
		}
	}

	return red;
}

vector<Point> findTemplate(String source, int min, int max, bool show)
{
	src = imread(source, 1);

	if (!src.data)
	{
		cout << "Sth went wrong";
	}
	pyrDown(src, src);
	pyrDown(src, src);

	/// Create a matrix of the same type and size as src (for dst)
	dst.create(src.size(), src.type());

	/// Convert the image to grayscale
	cvtColor(src, src_gray, COLOR_BGR2GRAY);

	/// Reduce noise with a kernel 3x3
	blur(src_gray, detected_edges, Size(3, 3));

	/// Canny detector
	int product = lowThreshold * ratio_t;
	Canny(detected_edges, detected_edges, lowThreshold, product, kernel_size);

	/// Using Canny's output as a mask, we display our result
	dst = Scalar::all(0);

	src.copyTo(dst, detected_edges);
	Mat structuring_element(3, 3, CV_8U, Scalar(1));
	morphologyEx(detected_edges, detected_edges, MORPH_CLOSE, structuring_element);

	vector<vector<Point>> contours;
	findContours(detected_edges, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	// Contours analyze
	int i_max = 0;
	int count = 0;
	for (int i = 0; i < contours.size(); i++)
	{
		if (contours[i].size() >= contours[i_max].size())
			i_max = i;
		double area = contourArea(contours[i]);
		if (area > min && area <max) // 3500 7500
		{
			
			count++;
		}
	}
	drawContours(src, contours, i_max, Scalar(0, 255, 0), 4, 8);
	if (show)
	{
		namedWindow(source, WINDOW_NORMAL);
		imshow(source, src);
		namedWindow(source + "edges", WINDOW_NORMAL);
		imshow(source + "edges", detected_edges);
	}

	return contours[i_max];
}

int method2()
{
	//prepare templates 
	trefl = findTemplate("templates/trefl.jpg", 1, 100, false);
	karo = findTemplate("templates/karo.jpg", 1, 100, false); 
	pik = findTemplate("templates/pik.jpg", 1, 100, false);
	kier = findTemplate("templates/kier.jpg", 500, 10000, false);

	two = findTemplate("templates/two.jpg", 100, 10000, false);
	three = findTemplate("templates/three.jpg", 100, 10000, false);
	four = findTemplate("templates/four.jpg", 100, 10000, false);
	five = findTemplate("templates/five.jpg", 100, 10000, false);
	six = findTemplate("templates/six.jpg", 100, 10000, false);
	seven = findTemplate("templates/seven.jpg", 100, 10000, false);
	eight = findTemplate("templates/eight.jpg", 5000, 10000, false);
	nine = findTemplate("templates/nine.jpg", 1000000, 9000000, false);
	ten = findTemplate("templates/zero.jpg", 1000, 10000, false);
	jack = findTemplate("templates/jack.jpg", 100, 10000, false);
	queen = findTemplate("templates/queen.jpg", 5000, 10000, false);
	king = findTemplate("templates/king.jpg", 100, 100000, false);
	ace = findTemplate("templates/ace.jpg", 100, 10000, false);

	/// Load an image
	string input = "";
	cout << "Which test do You want to make? <30-51>" << endl;
	cin >> input;

	src = imread("test/test"+input+".jpg", 1);

	if (!src.data)
	{
		return -1;
	}
	pyrDown(src, src);
	pyrDown(src, src);

	/// Create a matrix of the same type and size as src (for dst)
	dst.create(src.size(), src.type());

	/// Convert the image to grayscale
	cvtColor(src, src_gray, COLOR_BGR2GRAY);

	/// Reduce noise with a kernel 3x3
	blur(src_gray, detected_edges, Size(3, 3));

	/// Canny detector
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio_t, kernel_size);

	/// Using Canny's output as a mask, we display our result
	dst = Scalar::all(0);

	src.copyTo(dst, detected_edges);
	
	vector<vector<Point>> contours;
	findContours(detected_edges, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	if (contours.size() > 50)
	{
		src = fillRectangle(contours, src);
		/// Convert the image to grayscale
		cvtColor(src, src_gray, COLOR_BGR2GRAY);

		/// Reduce noise with a kernel 3x3
		blur(src_gray, detected_edges, Size(3, 3));

		/// Canny detector
		Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio_t, kernel_size);

		/// Using Canny's output as a mask, we display our result
		dst = Scalar::all(0);

		src.copyTo(dst, detected_edges);

		findContours(detected_edges, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
	}

	bool red = isRed(src);
	
	// Contours analyze
	int count = 0;
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area > 5 && area<100000) // 3500 7500
		{
			drawContours(src, contours, i, Scalar(0, 255, 0), 2, 8);
			count++;
		}
	}	

	// comparison
	bool recognised = false;
	bool pik_recognised = false;
	for (int i = 0; i < contours.size(); i++)
	{
		double a, b, c;
		
		if (red)
		{
			//KARO
			a = matchShapes(karo, contours[i], CONTOURS_MATCH_I1, 0);
			b = matchShapes(karo, contours[i], CONTOURS_MATCH_I3, 0);
			c = matchShapes(karo, contours[i], CONTOURS_MATCH_I2, 0);
			if (b < 0.1 && a < 0.1 && c < 0.15)
			{
				cout << "KARO " << i << " " << a << " " << b << " " << c << endl;
			}
			//KIER
			a = matchShapes(kier, contours[i], CONTOURS_MATCH_I1, 0);
			b = matchShapes(kier, contours[i], CONTOURS_MATCH_I3, 0);
			c = matchShapes(kier, contours[i], CONTOURS_MATCH_I2, 0);
			if (b < 0.1 && a < 0.1 && 0.2)
			{
				cout << "KIER " << i << " " << a << " " << b << " "<<c<<endl;
			}
		}
		else {
			//PIK
			double a, b, c;
			a = matchShapes(pik, contours[i], CONTOURS_MATCH_I1, 0);
			b = matchShapes(pik, contours[i], CONTOURS_MATCH_I3, 0);
			c = matchShapes(pik, contours[i], CONTOURS_MATCH_I2, 0);
			if (b < 0.5 && a < 0.1 && c < 0.3)
			{
				cout << "PIK " << i << " " << a << " " << b << " " << c << endl;
				pik_recognised = true;
			}
		}
		//TWO
		a = matchShapes(two, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(two, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(two, contours[i], CONTOURS_MATCH_I2, 0);
		if (a < 1 && b < 0.1 && c<0.9)
			cout << "TWO " << i << " " << a << " " << b << " " << c << endl;

		//THREE
		a = matchShapes(three, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(three, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(three, contours[i], CONTOURS_MATCH_I2, 0);

		if (b < 0.25 && a < 0.3 && c<0.5)
		{
			cout << "THREE " << i << " " << a << " " << b << " "<<c<<endl;
			recognised = true;
		}
		//FOUR
		a = matchShapes(four, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(four, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(four, contours[i], CONTOURS_MATCH_I2, 0);
		if (b < 0.1 && a < 0.1)
		{
			cout << "FOUR " << i << " " << a << " " << b << " "<<c <<endl;
			recognised = true;
		}
		//FIVE
		a = matchShapes(five, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(five, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(five, contours[i], CONTOURS_MATCH_I2, 0);
		if (b < 0.25 && a < 0.25 && c < 1)
		{
			cout << "FIVE " << i << " " << a << " " << b << " "<<c<<endl;
			recognised = true;
		}
		//SIX
		a = matchShapes(six, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(six, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(six, contours[i], CONTOURS_MATCH_I2, 0);
		if (b < 0.09 && a < 0.15 && c<0.7) 
		{
			cout << "SIX " << i << " " << a << " " << b << " "<< c<< endl;
			recognised = true;
		}
		//SEVEN
		a = matchShapes(seven, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(seven, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(seven, contours[i], CONTOURS_MATCH_I2, 0);
		if (b < 0.1 && a < 0.5 && c < 0.8)
		{
			cout << "SEVEN " << i << " " << a << " " << b << " " << c << endl;
			recognised = true;
		}		
		//NINE
		a = matchShapes(nine, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(nine, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(nine, contours[i], CONTOURS_MATCH_I2, 0);
		if (b < 0.1 && a < 0.1 && c<0.2)
		{
			cout << "NINE " << i << " " << a << " " << b << " "<< c<< endl;
			recognised = true;
		}
		
		//JACK
		a = matchShapes(jack, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(jack, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(jack, contours[i], CONTOURS_MATCH_I2, 0);
		if (b < 1 && a <  1 && c<1.5)
		{
			cout << "JACK " << i << " " << a << " " << b << " " <<c<<endl;
			recognised = true;
		}
		//KING
		a = matchShapes(king, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(king, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(king, contours[i], CONTOURS_MATCH_I2, 0);
		if (b < 1 && a < 0.8 && c<1.5)
		{
			cout << "KING " << i << " " << a << " " << b << " "<<c<<endl;
			recognised = true;
		}
		//ACE 
		a = matchShapes(ace, contours[i], CONTOURS_MATCH_I1, 0);
		b = matchShapes(ace, contours[i], CONTOURS_MATCH_I3, 0);
		c = matchShapes(ace, contours[i], CONTOURS_MATCH_I2, 0);
		if (b < 0.2 && a < 0.3 && c<1) 
		{
			cout << "ACE " << i << " " << a << " " << b << " "<<c<< endl;
			recognised = true;
		}
	}
	if (!recognised)
	{
		bool isQueen = false;
		for (int i = 0; i < contours.size(); i++)
		{
			double a, b, c;
			
			//QUEEN
			a = matchShapes(queen, contours[i], CONTOURS_MATCH_I1, 0);
			b = matchShapes(queen, contours[i], CONTOURS_MATCH_I3, 0);
			c = matchShapes(queen, contours[i], CONTOURS_MATCH_I2, 0);
			if (b < 0.1 && a < 0.1 && c<0.16)
			{
				cout << "QUEEN " << i << " " << a << " " << b << " " << c << endl;
				isQueen = true;
			}
			//EIGHT
			if (!isQueen)
			{
				a = matchShapes(eight, contours[i], CONTOURS_MATCH_I1, 0);
				b = matchShapes(eight, contours[i], CONTOURS_MATCH_I3, 0);
				c = matchShapes(eight, contours[i], CONTOURS_MATCH_I2, 0);
				if (b < 0.15 && a < 0.2 && c < 0.2)
					cout << "EIGHT " << i << " " << a << " " << b << " " << c << endl;
				
			}
		}
		if (!isQueen)
		{
			for (int i = 0; i < contours.size(); i++)
			{
				double a, b, c;
				//TEN
				a = matchShapes(ten, contours[i], CONTOURS_MATCH_I1, 0);
				b = matchShapes(ten, contours[i], CONTOURS_MATCH_I3, 0);
				c = matchShapes(ten, contours[i], CONTOURS_MATCH_I2, 0);
				if (b < 0.1 && a < 0.05 && c < 0.1)
				{
					cout << "TEN " << i << " " << a << " " << b << " " << c << endl;
					recognised = true;
				}
			}
		}
	}
	if (!pik_recognised && !red)
	{
		for (int i = 0; i < contours.size(); i++)
		{
			//TREFL
			double a = matchShapes(trefl, contours[i], CONTOURS_MATCH_I1, 0);
			double b = matchShapes(trefl, contours[i], CONTOURS_MATCH_I3, 0);
			double c = matchShapes(trefl, contours[i], CONTOURS_MATCH_I2, 0);
			if (b < 0.30 && a < 0.30 && c < 0.7)
			{
				cout << "TREFL " << i << " " << a << " " << b << " " << " " << c << endl;
			}
		}
	}

	waitKey(0);
	return 0;
}

int main()
{
	if (method2() == -1)
		return -1;
}