#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

#include <math.h>

using namespace cv;
using namespace std;
//
//void wave(const Mat& image,Mat& result) {
//
//	Mat srcX(image.rows,image.cols,CV_32F);
//	Mat srcY(image.rows,image.cols,CV_32F);
//
//	for (int i = 0; i < image.rows; i++)
//	{
//		for (int j = 0; j < image.cols; j++)
//		{
//			srcX.at<float>(i, j) = j;
//			srcY.at<float>(i, j) = i + 3 * sin(j/6.0);
//		}
//	}
//	remap(image,result,srcX,srcY,INTER_LINEAR);
//}
//
//int main() {
//	Mat image = imread("D:/opencv/test_source/images/boldt.jpg",0);
//
//	namedWindow("Image");
//	imshow("Image",image);
//
//	Mat result;
//	wave(image,result);
//
//	namedWindow("Remapped image");
//	imshow("Remapped image",result);
//
//	waitKey();
//	return 0;
//}