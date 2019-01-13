//用cv::dft() 和cv::idft() 加速卷积计算
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main_121() {
	Mat A = imread("D:/opencv/test_source/meinv.jpg",0);
	if (A.empty())
	{
		cout << "can not load file" << endl;
		return 0;
	}
	Size patchSize(100,100);
	Point topleft(A.cols /2,A.rows /2);
	Rect roi(topleft.x,topleft.y,patchSize.width,patchSize.height);
	Mat B = A(roi);

	int dft_M = getOptimalDFTSize(A.rows + B.rows - 1);
	int dft_N = getOptimalDFTSize(A.cols + B.cols - 1);
	cout << "dft_M = " << dft_M << " dft_N = " << dft_N << endl;

	Mat dft_A = Mat::zeros(dft_M,dft_N,CV_32F);
	Mat dft_B = Mat::zeros(dft_M,dft_N,CV_32F);

	Mat dft_A_part = dft_A(Rect(0,0,A.cols,A.rows));
	Mat dft_B_part = dft_B(Rect(0,0,B.cols,B.rows));

	A.convertTo(dft_A_part,dft_A_part.type(),1,-mean(A)[0]);
	B.convertTo(dft_B_part,dft_B_part.type(),1,-mean(B)[0]);

	dft(dft_A,dft_A,0,A.rows);
	dft(dft_B,dft_B,0,B.rows);

	mulSpectrums(dft_A,dft_B,dft_A,0,true);
	idft(dft_A,dft_A,DFT_SCALE,A.rows +B.rows -1);

	Mat corr = dft_A(Rect(0,0,A.cols + B.cols -1,A.rows + B.rows -1));
	normalize(corr,corr,0,1,NORM_MINMAX,corr.type());
	pow(corr,3.0,corr);

	B ^= Scalar::all(255);

	imshow("Image",A);
	imshow("Roi",B);
	imshow("Correlation",corr);

	waitKey();
	return 0;
}