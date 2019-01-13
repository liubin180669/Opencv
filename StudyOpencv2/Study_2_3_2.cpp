#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*
void colorReduce(Mat image,int div = 64) {
	int n1 = image.rows;
	int nc = image.cols * image.channels();

	for (int j = 0; j < n1; j++)
	{
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++)
		{
			data[i] = data[i] / div*div + div / 2;
		}
	}

}

void colorReduce2(Mat image,int div = 64) {
	int n1 = image.rows;
	int nc = image.cols *image.channels();
	uchar div2 = div >> 1;
	for (int j = 0; j < n1; j++)
	{
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++)
		{
			//int v = *data;
			//*data++ = v - v%div + div2;
			*data++ = *data / div*div + div2;
		}
	}
}

void colorReduce3(Mat image, int div = 64) {
	int n1 = image.rows;
	int nc = image.cols * image.channels();
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);

	uchar mask = 0xFF << n;
	uchar div2 = 1 << (n -1);
	for (int j = 0; j < n1; j++)
	{
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++)
		{
			*data &= mask;
			*data++ |= div2;
		}
	}
}

void colorReduce4(Mat image,int div = 64) {
	int n1 = image.rows;
	int nc = image.cols * image.channels();
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
	int step = image.step;
	cout << "step = " << step << " nc = "<< nc << " nl ="<< n1 <<endl;
	uchar mask = 0xFF << n;
	uchar div2 = div >> 1;
	uchar* data = image.data;
	for (int j = 0; j < n1; j++)
	{
		for (int i = 0; i < nc; i++)
		{
			*(data + i) &= mask;
			*(data + i) += div2;
		}
		data += step;
	}
}

void colorReduce5(Mat image, int div = 64) {
	int n1 = image.rows;
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
	uchar mask = 0xFF << n;
	for (int j = 0; j < n1; j++)
	{
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < image.cols * image.channels(); i++)
		{
			*data &= mask;
			*data++ += div / 2;
		}
	}

}

void colorReduce6(Mat image,int div = 64) {
	int n1 = image.rows;
	int nc = image.cols * image.channels();
	if (image.isContinuous()) {
		nc = nc * n1;
		n1 = 1;
	}
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
	cout << " n = " << n << endl;
	uchar mask = 0xFF << n;
	cout << " mask  = " << mask << endl;
	uchar div2 = div >> 1;
	cout << " div2 = " << div2 << endl;
	for (int j = 0; j < n1; j++)
	{
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++)
		{
			*data &= mask;
			*data++ += div2;
		}
	}
}

void colorReduce7(Mat image,int div = 64) {
	if (image.isContinuous())
	{
		image.reshape(1, 1);
	}
	int n1 = image.rows;
	int nc = image.cols*image.channels();
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
	uchar mask = 0xFF << n;
	uchar div2 = div >> 1;
	for (int j = 0; j < n1; j++)
	{
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++)
		{
			*data &= mask;
			*data++ += div2;
		}
	}
}

void colorReduce8(Mat image,int div = 64) {
	Mat_<Vec3b>::iterator it = image.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = image.end<Vec3b>();
	uchar div2 = div >> 1;
	for (;it != itend; ++it)
	{
		(*it)[0] = (*it)[0] / div*div + div;
		(*it)[1] = (*it)[1] / div*div + div;
		(*it)[2] = (*it)[2] / div*div + div;
	}
}

void colorReduce9(Mat image,int div = 64) {
	MatIterator_<Vec3b> it = image.begin<Vec3b>();
	MatIterator_<Vec3b> itend = image.end<Vec3b>();
	const Vec3b  offset(div/2,div/2,div/2);
	for (; it != itend; it++)
	{
		*it = *it / div*div + offset;
	}
}

void colorReduce10(Mat image,int div = 64) {
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
	uchar mask = 0xFF << n;
	uchar div2 = div >> 1;
	Mat_<Vec3b>::iterator it = image.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = image.end<Vec3b>();
	for (; it != itend; it++)
	{
		(*it)[0] &= mask;
		(*it)[0] += div2;
		(*it)[1] &= mask;
		(*it)[1] += div2;
		(*it)[2] &= mask;
		(*it)[2] += div2;
	}
}

void colorReduce11(Mat image,int div = 64) {
	Mat_<Vec3b> cimage = image;
	Mat_<Vec3b>::iterator it = cimage.begin();
	Mat_<Vec3b>::iterator itend = cimage.end();
	uchar div2 = div >> 1;
	for (;it != itend; it++)
	{
		(*it)[0] = (*it)[0] / div*div +div2;
		(*it)[1] = (*it)[1] / div*div + div2;
		(*it)[2] = (*it)[2] / div*div + div2;
	}
}

void colorReduce12(Mat image ,int div = 64) {//²âÊÔÃ»Í¨¹ý
	int n1 = image.cols;
	int nc = image.rows;
	uchar div2 = div >> 1;
	for (int j = 0; j< n1; j++)
	{
		for (int i = 0; i < nc; i++)
		{
			image.at<Vec3b>(j, i)[0] = image.at<Vec3b>(j, i)[0] / div*div + div2;
			//image.at<Vec3b>(j, i)[1] = image.at<Vec3b>(j, i)[1] / div*div + div2;
			//image.at<Vec3b>(j, i)[2] = image.at<Vec3b>(j, i)[2] / div*div + div2;
		}
	}
}

void colorReduce13(Mat image,int div = 64) {
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
	uchar mask = 0xFF << n;
	image = (image&Scalar(mask, mask, mask)) + Scalar(div/2,div/2,div/2);
}

void colorReduce14(cv::Mat image, int div = 64) {
	cv::Mat lookup(1, 256, CV_8U);
	for (int i = 0; i<256; i++) {
		lookup.at<uchar>(i) = i / div*div + div / 2;
	}
	cv::LUT(image, lookup, image);
}


int main() {
	Mat image = imread("D:/opencv/test_source/images/boldt.jpg");
	const int64 start = getTickCount();


	//colorReduce(image,64);
	//colorReduce2(image,64);
	//colorReduce3(image,64);
	//colorReduce4(image,64);
	//colorReduce5(image,64);
	//colorReduce6(image,64);
	//colorReduce7(image,64);
	//colorReduce8(image, 64);
	//colorReduce9(image, 64);
	//colorReduce10(image, 64);
	//colorReduce11(image, 64);
	//colorReduce12(image, 64);
	//colorReduce13(image, 64);
	colorReduce14(image, 64);


	double duration = (getTickCount() - start) / getTickFrequency();
	cout << "Duration = " << duration << " secs" << endl;
	namedWindow("Image");
	imshow("Image",image);
	waitKey(0);



	return 0;
}
*/