#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <opencv2/features2d/features2d.hpp>


#include "Kanten.h"
#include "BildLaden.h"

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
	//Bild ins Programm laden
	Mat bildEingang = bildOeffnen(argc, argv);
	

	//bild schwarz-weiß färben für Kantenerkennung
	Mat bildSw;
	cvtColor(bildEingang, bildSw, CV_BGR2GRAY);


	//kantenerkennung
	Mat kantenbild = kanten(bildSw);
	
	bildZeigen(bildEingang);

}