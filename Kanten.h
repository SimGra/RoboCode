#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <opencv2/features2d/features2d.hpp>

using namespace cv;
using namespace std;


Mat kanten(Mat image)
{
	
	//Mit Gauss filter verschwimmen lassen
	Mat gauss, cgauss;
	GaussianBlur(image, gauss, Size(5, 5), 0, 0);
	cvtColor(gauss, cgauss, CV_GRAY2BGR);



	//Canny-Bild erzeugen
	Mat dst, cdst;
	Canny(gauss, dst, 50, 200, 3);
	cvtColor(dst, cdst, CV_GRAY2BGR);


	//Linien erkennen und erzeugen
	vector<Vec4i> lines;
	HoughLinesP(dst, lines, 1, CV_PI / 180, 50, 50, 10);
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);
	}

	////bilder anzeigen
	//imshow("original", image);
	//imshow("gauss", cgauss);
	//imshow("linienerkennung", cdst);

	//waitKey(0);

	return cdst;
}