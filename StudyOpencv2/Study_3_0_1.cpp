#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>

#include "colordetector.h"

//int main() {
//	ColorDetector cdetect;
//	Mat image = imread("D:/opencv/test_source/images/boldt.jpg");
//	if (image.empty())
//	{
//		return 0;
//	}
//	namedWindow("Original Image");
//	imshow("Original Image", image);
//
//	cdetect.setTargetColor(230,190,120);
//	namedWindow("result");
//	Mat result = cdetect.process(image);
//	imshow("result",result);
//
//	ColorDetector colorDetector(230,190,130,45,true);
//	namedWindow("result (functor)");
//	result = colorDetector(image);
//	imshow("result (functor)",result);
//
//
//
//
//	waitKey();
//	return 0;
//}