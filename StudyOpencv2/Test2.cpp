#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//int main() {
//
//	Mat m = Mat::eye(10,10,CV_32FC1);
//
//	printf("Element (3,3) %f\n",m.at<float>(3,3));
//
//	Mat m2 = Mat::eye(10,10,CV_32FC2);
//	printf("Element(3,3) (%f,%f)\n",m2.at<Vec2f>(3,3)[0],m2.at<Vec2f>(3,3)[1]);
//
//	/*mat m3 = mat::eye(10,10,cv::datatype<cv::complexf>::generic_type);
//	printf("element (3,3) is %f + i%f\n",m3.at<cv::complexf>(3,3).re,m.at<cv::complexf>(3,3).im);*/
//
//	int sz[3] = {4,4,4};
//	Mat m4(3,sz,CV_32FC3);
//	randn(m4,-1.0f,1.0f);
//	float max = 0.0f;
//	/*MatConstIterator<Vec3f> it = m4.begin();*/
//
//
//
//	
//
//	waitKey(0);
//	int a;
//	cin >> a;
//	return 0;
//}