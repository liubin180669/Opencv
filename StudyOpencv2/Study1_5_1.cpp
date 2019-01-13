#include <iostream>

#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>

using namespace cv;

int main_1_5_1()
{
	namedWindow("Image");
	Mat image = imread("D:/opencv/test_source/images/puppy.bmp");
	Mat logo = imread("D:/opencv/test_source/images/smalllogo.png");

	//Mat imageROI(image,Rect(image.cols - logo.cols ,image.rows - logo.rows,logo.cols,logo.rows));

	//logo.copyTo(imageROI);

	//imshow("Image",image);
	//waitKey(0);

	Mat imageROI;
	image = imread("D:/opencv/test_source/images/puppy.bmp");
	imageROI = image(Rect(image.cols - logo.cols,image.rows - logo.rows ,logo.cols ,logo.rows));
	Mat mask(logo);
	logo.copyTo(imageROI,mask);
	imshow("Image",image);


	waitKey(0);
	return 0;
}