#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void detect_face();
void detect_eyes();
void video_in();
void decode_qrcode();


int main()
{
	//detect_face();
	//detect_eyes();
	//video_in();
	decode_qrcode();

	return 0;
}

void detect_face()
{
	Mat src1 = imread("chams2.png");

	if (src1.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	CascadeClassifier classifier("haarcascade_frontalface_default.xml");

	if (classifier.empty()) {
		cerr << "XML load failed!" << endl;
		return;
	}

	vector<Rect> faces;
	classifier.detectMultiScale(src1, faces);

	for (Rect rc : faces) {
		rectangle(src1, rc, Scalar(255, 0, 255), 2);
	}

	imshow("src", src1);

	waitKey(0);
	destroyAllWindows();
}

void detect_eyes()
{
	Mat src = imread("face.bmp");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	CascadeClassifier face_classifier("haarcascade_frontalface_default.xml");
	CascadeClassifier eye_classifier("haarcascade_eye.xml");

	if (face_classifier.empty() || eye_classifier.empty()) {
		cerr << "XML load failed!" << endl;
		return;
	}

	vector<Rect> faces;
	face_classifier.detectMultiScale(src, faces);

	for (Rect face : faces) {
		rectangle(src, face, Scalar(255, 0, 255), 2);

		Mat faceROI = src(face);
		vector<Rect> eyes;
		eye_classifier.detectMultiScale(faceROI, eyes);

		for (Rect eye : eyes) {
			Point center(eye.x + eye.width / 2, eye.y + eye.height / 2);
			circle(faceROI, center, eye.width / 2, Scalar(255, 0, 0), 2, LINE_AA);
		}
	}

	imshow("src", src);

	waitKey(0);
	destroyAllWindows();
}

void video_in() {
	
	VideoCapture cap("me.mp4");
	CascadeClassifier classifier("haarcascade_frontalface_default.xml");

	if (classifier.empty())
	{
		cerr << "xml load failed! " << endl;
		return;
	}
		if (!cap.isOpened())
		{
			cerr << "video open failed! " << endl;
			return;
		}

		cout << "frame width" << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
		cout << "frame height" << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
		cout << "frame count" << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

		double fps = cap.get(CAP_PROP_FPS);
		cout << "FPS: " << fps << endl;

		int delay = cvRound(1000 / fps);

		Mat frame, inversed;
		while (true)
		{
			cap >> frame;
			if (frame.empty())
				break;

			
			vector<Rect> faces;
			classifier.detectMultiScale(frame, faces);

			for (Rect rc : faces )
			{
				rectangle(frame, rc, Scalar(255, 0, 255), 2);
			}

			imshow("frame", frame);
			

			if (waitKey(delay) == 27)
				break;

		}

		destroyAllWindows();
}

void decode_qrcode() {
	
	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cerr << "camera open failed! " << endl;
		return;
	}

	QRCodeDetector detector;

	Mat frame;
	while (true)
	{
		cap >> frame;

		if (frame.empty())
		{
			cerr << "frame load failed! " << endl;
			break;
		}
		vector<Point> points;

		String info = detector.detectAndDecode(frame, points);

		if (!info.empty())
		{
			polylines(frame, points, true, Scalar(0, 0, 255), 2);
			putText(frame, info, Point(10, 30), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255));
		}

		imshow("frame", frame);
		if (waitKey(1) == 27)
			break;
	}
}
