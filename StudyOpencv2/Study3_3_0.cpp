#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main() {
	Mat image = imread("D:/opencv/test_source/images/boldt.jpg");
	if (!image.data)
	{
		return 0;
	}



	waitKey();
	return 0;
}