#include "cv.h"
#include "highgui.h"
#include <iostream>
#include <cstdlib>

using namespace cv;
using namespace std;
    
	const string filename = "/home/marcgenevat/catkin_ws/src/opencv_face/src/video.mpeg";
	String face_cascade_name = "/home/marcgenevat/catkin_ws/src/opencv_face/src/haarcascade_frontalface_default.xml";
	CascadeClassifier face_cascade;


void detectAndDisplay( Mat frame ) {
	vector<Rect> faces;
	Mat frame_gray;
	
	//Convert frame from BGR to grayscale format
	cvtColor( frame, frame_gray, CV_BGR2GRAY );
	
	face_cascade.detectMultiScale(frame_gray, faces, 1.3, 4, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));

	for( int i = 0; i < faces.size(); i++) {
		//Calculate center
		Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );

		//Draw a face-circle
		circle( frame, center, faces[i].width/2, Scalar( 255, 0, 255 ), 2 );

		//Draw a nose-circle
		circle( frame, center, faces[i].width/8, Scalar( 0, 0, 255 ), -1 );
	}

	imshow("Face_detector", frame);
}

	
int main(int argc, char *argv[]) {

	Mat frame;

	//Load the cascade
	if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };

	//Read the video
	VideoCapture capture(filename);
    if( !capture.isOpened() )	throw "Error when reading steam_avi";

	while(true) {
		//Get a frame		
		capture >> frame;

		//Apply the classifier to the frame
		if( !frame.empty() )	detectAndDisplay( frame );
	
		else {
			cout << "No captured frame -- Break!" << endl;
			break;		
		}
		
		int c = waitKey(10);
		if( (char)c == 'c' ) break;
	}
	return 0;
}
