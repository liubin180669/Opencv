#pragma once
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>

using namespace std;
using namespace cv;

class ColorDetector
{
private:

	int maxDist;
	Vec3b target;
	Mat converted;
	bool useLab;
	Mat result;

public:
	ColorDetector() :maxDist(100), target(0, 0, 0), useLab(false) {}
	ColorDetector(bool useLab) :maxDist(100), target(0, 0, 0), useLab(useLab) {}
	ColorDetector(uchar blue, uchar green, uchar red, int mxDist = 100, bool useLab = false) :maxDist(mxDist)
		, useLab(useLab) {
		setTargetColor(blue,green,red);
	}

	int getDistanceToTargetColor(const Vec3b& color) const {
		return getColorDistance(color,target);
	}
	
	int getColorDistance(const Vec3b& color1,const Vec3b& color2) const {
		return abs(color1[0]-color2[0])+
			abs(color1[1] - color2[1])+
			abs(color1[2] - color2[2]);
	}

	Mat process(const Mat& image);

	Mat operator()(const Mat& image) {
		Mat input;
		if (useLab) {
			cvtColor(image,input,CV_BGR2Lab);
		}
		else {
			input = image;
		}
		Mat output;
		absdiff(input,Scalar(target),output);
		vector<Mat> images;
		split(output,images);
		output = images[0] + images[1] + images[2];
		threshold(output,output,maxDist,255,THRESH_BINARY_INV);
		return output;
	}

	void setColorDistanceThreshold(int distance) {
		if (distance < 0) {
			distance = 0;
		}
		maxDist = distance;
	}

	void setTargetColor(uchar blue,uchar green,uchar red) {
		target = Vec3b(blue,green,red);
		if (useLab) {
			Mat tmp(1,1,CV_8UC3);
			tmp.at<Vec3b>(0, 0) = Vec3b(blue,green,red);
			cvtColor(tmp,tmp,CV_BGR2Lab);
			target = tmp.at<Vec3b>(0,0);
		}
	}

	void setTargetColor(Vec3b color) {
		target = color;
	}

	Vec3b getTargetColor() const{
		return target;
	}

};

