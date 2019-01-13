#include <opencv2\opencv.hpp>
#include <iostream>
#include <opencv2\highgui.hpp>

using namespace std;
using namespace cv;

void help(char ** argv) {
	cout << "Call:\n" << argv[0] << endl;
}

void sum_rgb(const Mat& src, Mat& dst) {
	vector <Mat> planes;
	split(src,planes);
	Mat b = planes[0], g = planes[1], r = planes[2], s;

	s = Mat::zeros(b.size(),CV_32F);
	accumulate(b,s);
	accumulate(g, s);
	accumulate(r, s);


	//addWeighted(r,1.0/3,g,1.0/3,0.0,s);
	//addWeighted(s,1.0,b,1.0/3,0.0,s);

	threshold(s,s,200,100,THRESH_TRUNC);
	s.convertTo(dst,b.type());

}

//int main(int argc,char** argv) {
//	//help(argv);
//	
//	Mat src = imread("D:/opencv/test_source/meinv.jpg");
//	Mat dst;
//	if (src.empty())
//	{
//		cout << "can not load" << endl;
//	}
//	sum_rgb(src,dst);
//
//	imshow("meinv.jpg",dst);
//
//	waitKey(0);
//	return 0;
//}



//int main() {
//	char* s0 = "100";
//	char* s1 = "3";
//	char* s2 = "11";
//
//	double fixed_threshold = (double)atof(s0);
//	int threshold_type = THRESH_BINARY; // CV_THRESH_BINARY_INV;
//	int apative_method = ADAPTIVE_THRESH_MEAN_C; // ADAPTIVE_THRESH_GAUSSIAN_C;
//
//	int block_size = atoi(s1);
//	double offset = (double)atof(s2);
//
//	Mat igray = imread("D:/opencv/test_source/meinv.jpg",IMREAD_GRAYSCALE);
//	
//	if (igray.empty())
//	{
//		cout << "can't find jpg" << endl;
//	}
//	Mat it, iat;
//
//	threshold(igray,it,fixed_threshold,255,threshold_type);
//
//	adaptiveThreshold(igray,iat,255,apative_method,threshold_type,block_size,offset);
//
//	imshow("Raw",igray);
//	imshow("Threshold",it);
//	imshow("Adapter Threshold",iat);
//	waitKey(0);
//	return 0;
//}