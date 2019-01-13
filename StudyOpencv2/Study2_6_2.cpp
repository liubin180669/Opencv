#include <vector>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace cv;
using namespace std;

//int main()
//{
//	Mat image1;
//	Mat image2;
//
//	image1 = imread("D:/opencv/test_source/images/boldt.jpg");
//	image2 = imread("D:/opencv/test_source/images/rain.jpg"); 
//
//	if (!image1.data)
//	{
//		return 0;
//	}
//	if (!image2.data)
//	{
//		return 0;
//	}
//	namedWindow("Image1");
//	imshow("Image1",image1);
//	namedWindow("Image2");
//	imshow("Image2",image2);
//
//	Mat result;
//
//	addWeighted(image1,0.7,image2,0.9,0.,result);
//	namedWindow("result");
//	imshow("result",result);
//
//	result = 0.7*image1 + 0.9*image2;
//	namedWindow("result with operators");
//	imshow("result with operators",result);
//
//	image2 = imread("D:/opencv/test_source/images/rain.jpg",0);
//
//	vector<Mat> planes;
//	split(image1,planes);
//	planes[0] += image2;
//	merge(planes,result);
//
//	namedWindow("Result on blue channels");
//	imshow("Result on blue channels",result);
//
//	waitKey();
//	return 0;
//}