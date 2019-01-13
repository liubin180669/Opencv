//͸�ӱ任
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main2() {

	Mat src = imread("D:/opencv/test_source/meinv.jpg");
	if (src.empty())
	{
		cout << "Can not load file !" << endl;
		return -1;
	}
	Point2f srcQuad[] = {
		Point2f(0,0),
		Point2f(src.cols - 1,0),
		Point2f(src.cols - 1,src.rows - 1),
		Point2f(0,src.rows - 1)
	};

	Point2f dstQuad[] = {
		Point2f(src.cols*0.05f,src.rows*0.33f),
		Point2f(src.cols*0.9f,src.rows*0.25f),
		Point2f(src.cols*0.8f,src.rows*0.9f),
		Point2f(src.cols*0.2f,src.rows*0.7f)
	};

	Mat warp_mat = getPerspectiveTransform(srcQuad,dstQuad);
	Mat dst;
	warpPerspective(src,dst,warp_mat,src.size(),INTER_LINEAR,BORDER_CONSTANT,Scalar());
	for (int i = 0; i < 4; i++)
	{
		circle(dst,dstQuad[i],5,Scalar(255,0,255),-1,LINE_AA);
	}
	imshow("Perspective Transform Test",dst);

	waitKey(0);
	return 0;
}