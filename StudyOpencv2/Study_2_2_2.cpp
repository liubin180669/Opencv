#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <random>

using namespace cv;
using namespace std;

void salt(Mat image,int n) {
	default_random_engine generator;
	uniform_int_distribution<int> randomRow(0,image.rows - 1);
	uniform_int_distribution<int> randomCol(0,image.cols - 1);

	int i, j;
	for (int k = 0; k < n; k++)
	{
		i = randomCol(generator);
		j = randomRow(generator);
		if (image.type() == CV_8UC1)//µ¥Í¨µÀ
		{
			cout << "111111111" << endl;
			image.at<uchar>(j, i) = 255;
		}else if (image.type() == CV_8UC3) {
			cout << "2222222222" << endl;
			image.at<Vec3b>(j, i)[0] = 255;
			image.at<Vec3b>(j, i)[1] = 255;
			image.at<Vec3b>(j, i)[2] = 255;
		}

	}

}

void salt2(Mat image ,int n) {
	CV_Assert(image.type() == CV_8UC1);
	default_random_engine generator;
	uniform_int_distribution<int> randomRow(0,image.rows - 1);
	uniform_int_distribution<int> randowCol(0,image.cols - 1);

	Mat_<uchar> img(image);
	int i, j;
	for (int k = 0; k < n; k++)
	{
		i = randomRow(generator);
		j = randomRow(generator);
		img(j, i) = 255;
	}

}

int main_2_2_2() {
	Mat image = imread("D:/opencv/test_source/images/boldt.jpg",1);
	salt(image,3000);
	namedWindow("Image");
	imshow("Image",image);

	imwrite("D:/opencv/test_source/images/salted.bmp",image);
	waitKey(0);

	image = imread("D:/opencv/test_source/images/boldt.jpg", 0);
	salt2(image,500);
	namedWindow("Image");
	imshow("Image",image);

	waitKey(0);
	return 0;
}

