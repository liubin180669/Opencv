#include <iostream>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
using namespace std;
using namespace cv;

/*
void sharpen(const Mat &image,Mat& result) {
	result.create(image.size(),image.type());
	int nchannels = image.channels();
	cout << "nchannels = " << nchannels << endl;
	for (int j = 1; j < image.rows - 1; j++)
	{
		const uchar* previous = image.ptr<const uchar>(j - 1);
		const uchar* current = image.ptr<const uchar>(j);
		const uchar* next = image.ptr<const uchar>(j + 1);

		uchar* output = result.ptr<uchar>(j);
		for (int i = nchannels; i < (image.cols - 1)*nchannels; i++)
		{
			*output++ = saturate_cast<uchar>(5 * current[i] - current[i - nchannels] - current[i + nchannels] - previous[i] - next[i]);
		}
	}
	result.row(0).setTo(Scalar(0));
	result.row(result.rows -1).setTo(Scalar(0));
	result.col(0).setTo(Scalar(0));
	result.col(result.cols-1).setTo(Scalar(0));
}


int main() {
	Mat image = imread("D:/opencv/test_source/images/boldt.jpg");
	if (!image.data)
	{
		return 0;
	}
	Mat result;
	double time = static_cast<double>(getTickCount());
	sharpen(image,result);
	time = (static_cast<double>(getTickCount())- time)/ getTickFrequency();
	cout << "time = " << time << endl;

	namedWindow("Image");
	imshow("Image",result);
	waitKey();
	return 0;
}
*/
