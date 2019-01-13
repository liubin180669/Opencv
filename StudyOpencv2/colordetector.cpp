#include "colordetector.h"
#include <vector>

Mat ColorDetector::process(const Mat& image) {
	result.create(image.size(),CV_8U);
	if (useLab)
		cvtColor(image,converted,CV_BGR2Lab);

	Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
	Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();
	Mat_<uchar>::iterator itout = result.begin<uchar>();

	if (useLab) {
		it = converted.begin<Vec3b>();
		itend = converted.end<Vec3b>();
	}
	for (;it != itend; ++it,++itout)
	{
		if (getDistanceToTargetColor(*it)<maxDist)
		{
			*itout = 255;
		}
		else {
			*itout = 0;
		}
	}
	return result;
}