#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

//int main() {
//
//	namedWindow("video",WINDOW_AUTOSIZE);
//	VideoCapture cap;
//	cap.open(0);
//
//	if (!cap.isOpened())
//	{
//		printf("open error");
//	}
//	Mat frame;
//	for (;;)
//	{
//		cap >> frame;
//		if (frame.empty())
//		{
//			break;
//		}
//		imshow("video",frame);
//		if (waitKey(33) >=0)
//		{
//			break;
//		}
//	}
//	return 0;
//}
