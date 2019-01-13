#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main13_1() {
	Mat src = imread("D:/opencv/test_source/test3.jpg",1);
	if (src.empty())
	{
		cout << "can not find file" << endl;
		return -1;
	}
	Mat hsv;
	cvtColor(src,hsv,COLOR_BGR2HSV);

	float h_ranges[] = {0,100};
	float s_ranges[] = { 0,256 };
	const float* ranges[] = {h_ranges,s_ranges};
	int histSize[] = {30,32};
	int ch[] = {0,1};

	Mat hist;
	calcHist(&hsv,1,ch,cv::noArray(),hist,2,histSize,ranges,true);
	normalize(hist,hist,0,255,NORM_MINMAX);

	int scale = 10;
	Mat hist_img(histSize[0]*scale,histSize[1]*scale,CV_8UC3);

	for (int h = 0; h < histSize[0]; h++)
	{
		for (int s = 0; s < histSize[1]; s++)
		{
			float hval = hist.at<float>(h,s);
			rectangle(hist_img,Rect(h*scale,s*scale,scale,scale),
				Scalar::all(hval),-1);
		}
	}
	imshow("image",src);
	imshow("H-S histogram",hist_img);

	waitKey();
	return 0;
}
