
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


Mat colorFilter(Mat src)
{
	Mat colorsrc = src.clone();

	cvtColor(colorsrc, colorsrc, CV_RGB2YCrCb);
	assert(colorsrc.type() == CV_8UC3);

	Mat colorOnly;
	inRange(colorsrc, Scalar(16, 8, 80), Scalar(225, 150, 100), colorOnly);
	//cvtColor(colorOnly,colorOnly,CV_GRAY2RGB);
	return colorOnly;
}