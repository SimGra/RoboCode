#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <opencv2/features2d/features2d.hpp>

using namespace cv;
using namespace std;

Mat _src;
const char* _filename;

Mat bildOeffnen(int argc, char** argv)
{

		//Dateinamen festlegen
		_filename = argc >= 2 ? argv[1] : "C:/Users/Simon/Dropbox/Robocup_Torerkennung/image-386.png";
	
		//Datei Laden
		_src = imread(_filename, 1);

		return _src;
}

int bildZeigen(Mat image)
{
	//prüfen ob Datei ein Bild ist
	if (image.empty())
	{
		cout << "can not open " << _filename << endl;
		return -2;
	}


	//bild anzeigen
	imshow("Bild", image);

	waitKey(0);
	return -2;
}