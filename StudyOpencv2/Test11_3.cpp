//对数-极坐标变换
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main3() {
	Mat src = imread("D:/opencv/test_source/meinv.jpg");
	if (src.empty())
	{	
		cout << "Can not load file " << endl;
		return 0;
	}
	double M = atof("30");
	Mat dst(src.size(),src.type());
	Mat src2(src.size(),src.type());

	logPolar(src, dst, Point2f(src.cols*0.5f, src.rows*0.5f),M,INTER_LINEAR | WARP_FILL_OUTLIERS);

	logPolar(dst, src2, Point2f(src.cols*0.5f,src.rows*0.5f),M,INTER_LINEAR | WARP_INVERSE_MAP);

	imshow("log-polar",dst);
	imshow("inverse log-polar",src2);

	waitKey();
	return 0;
}