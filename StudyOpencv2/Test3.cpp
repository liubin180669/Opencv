#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//int main() {
//	Mat src1 = imread("D:/opencv/test_source/test2.jpg"); 
//	Mat src2 = imread("D:/opencv/test_source/fjy.jpg");
//
//	cout << "Test3 main" << endl;
//	if (!src1.empty() && !src2.empty())
//	{
//		cout << "src not empty" << endl;
//		int from_w = src1.size().width;
//		int from_h = src1.size().height;
//		
//		int to_w = src2.size().width;
//		int to_h = src2.size().height;
//
//		cout << "from_w = " << from_w << "from_h = " << from_h << endl;
//		cout << "to_w = " << to_w << " to_h = " << to_h << endl;
//
//		double alpha = (double)0.5;
//		double beta = (double)0.2;
//
//		int x = 30;
//		int y = 30;
//		/*Mat roi1(src1,Rect(x,y,from_w-1,from_h -1));
//		Mat roi2(src2,Rect(20,20,from_w-1,from_h-1));*/
//
//		Mat roi1(src1, Rect(x, y, 59, 59));
//		Mat roi2(src2, Rect(20, 20, 59,59));
//
//		addWeighted(roi1,alpha,roi2,beta,0.0,roi2);
//
//		namedWindow("Alpha",1);
//		imshow("Alpha",src2);
//		waitKey(0);
//	}
//	int a;
//	cin >> a;
//
//	return 0;
//}