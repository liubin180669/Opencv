#include <iostream>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>

using namespace cv;
using namespace std;

Mat function1() {
	Mat ima(500,500,CV_8U,50);
	return ima;
}

int main_Study1_4_1() {
	Mat image1(240,320,CV_8U,100);
	imshow("Image",image1);
	waitKey(0);

	image1.create(200,200,CV_8U);
	image1 = 200;
	imshow("Image", image1);
	waitKey(0);

	//Mat image2(240,320,CV_8UC3,cv::Scalar(0,0,255));
	Mat image2(Size(320,240),CV_8UC3);
	image2 = Scalar(0,0,255);
	imshow("Image",image2);
	waitKey(0);

	Mat image3 = imread("D:/opencv/test_source/images/puppy.bmp");
	Mat image4(image3);
	image1 = image3;
	image3.copyTo(image2);
	Mat image5 = image3.clone();
	flip(image3,image3,1);

	imshow("Image1",image1);
	imshow("Image2",image2);
	imshow("Image3",image3);
	imshow("Image4",image4);
	imshow("Image5",image5);
	waitKey(0);

	Mat gray = function1();
	imshow("image1",gray);
	waitKey(0);

	image1 = imread("D:/opencv/test_source/images/puppy.bmp",CV_LOAD_IMAGE_GRAYSCALE);
	image1.convertTo(image2,CV_32F,1/255.0,0.0);
	imshow("Image",image2);
	waitKey(0);

	return 0;
}