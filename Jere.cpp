// ConsoleApplication1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat colorFilter(const Mat& src)
{
	Mat colorsrc = src.clone();
	
	cvtColor(colorsrc,colorsrc, CV_RGB2YCrCb);
    assert(colorsrc.type() == CV_8UC3);

    Mat colorOnly;
    inRange(colorsrc, Scalar(16, 8, 80), Scalar(225, 150,100), colorOnly);
	//cvtColor(colorOnly,colorOnly,CV_GRAY2RGB);
    return colorOnly;
}

int main(int argc, char** argv)
{
	//Dateinamen festlegen
	const char* filename = argc >= 2 ? argv[1] : "C:/Users/LJ-Studio/Dropbox/Robocup_Torerkennung/image-486.png";

	//Datei Laden
	Mat src = imread(filename,1);

	//prüfen ob Datei ein Bild ist
	if (src.empty())
	{
		cout << "can not open " << filename << endl;
		return -2;
	}

	Mat colorOnly = colorFilter(src);

	//Mit Gauss filter verschwimmen lassen
	/*Mat gauss, cgauss;
	GaussianBlur(colorOnly, gauss, Size(7, 7), 0, 0);
	cvtColor(gauss, cgauss, CV_RGB2GRAY);*/


	//Canny-Bild erzeugen
	Mat dst, cdst;
	Canny(colorOnly, dst, 50, 200, 3);
	cvtColor(dst, cdst, CV_GRAY2BGR);

	//Linien erkennen und erzeugen
	vector<Vec4i> lines;
	HoughLinesP(dst, lines, 1, CV_PI / 180, 50, 50, 10);
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);
	}
	
	
	
	//bilder anzeigen
	imshow("original", src);
	//imshow("gauss", dst);
	imshow("colorOnly", colorOnly);
	imshow("linienerkennung", cdst);

	waitKey(0);

	return -1;
}
