//·ÂÉä±ä»»
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main1() {
	Mat src = imread("D:/opencv/test_source/meinv.jpg");
	if (src.empty()) {
		return 0;
	}
	Point2f srcTri[] = {
		Point2f(0,0),
		Point2f(src.cols - 1,0),
		Point2f(0,src.rows - 1)
	};
	Point2f dstTri[] = {
		Point2f(src.cols*0.f,src.rows*0.33f),
		Point2f(src.cols*0.85f,src.rows*0.25f),
		Point2f(src.cols*0.15f,src.rows*0.7f)
	};

	Mat warp_mat = getAffineTransform(srcTri,dstTri);
	Mat dst, dst2;
	warpAffine(src,dst,warp_mat,src.size(),INTER_LINEAR,BORDER_CONSTANT,Scalar());

	for (int i = 0; i < 3; i++)
	{
		circle(dst,dstTri[i],5,Scalar(255,0,255),-1,LINE_AA);
	}
	imshow("Affine Transform Test",dst);
	waitKey();

	for (int frame = 0; ; frame++)
	{
		Point2f center(src.cols *0.5f,src.rows *0.5f);
		double angle = frame * 3 % 360;
		double scale = (cos((angle - 60) * CV_PI / 180) + 1.05)*0.8;

		Mat rot_mat = getRotationMatrix2D(center,angle,scale);

		warpAffine(src,dst,rot_mat,src.size(),INTER_LINEAR,BORDER_CONSTANT,Scalar());

		imshow("Rotated Image", dst);
		if (waitKey(30) >= 0)
		{
			break;
		}
	}
	


	return 0;
}