//HoughCircles() 从灰度图中获取一组圆的序列
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main12_2() {

	Mat src, image;
	src = imread("D:/opencv/test_source/meinv.jpg",1);
	if (src.empty())
	{
		return -1;
	}
	cvtColor(src,image,CV_BGR2GRAY);
	GaussianBlur(image,image,Size(5,5),0,0);

	vector<Vec3f> circles;
	HoughCircles(image,circles,HOUGH_GRADIENT,2,image.cols/10);

	for (size_t i = 0; i < circles.size(); i++)
	{
		circle(src,
			Point(cvRound(circles[i][0]), cvRound(circles[i][1])),
			cvRound(circles[i][2]),
			Scalar(0,0,255),
			2,
			LINE_AA);
	}
	imshow("HoughCircles",src);


	waitKey();
	return 0;
}
