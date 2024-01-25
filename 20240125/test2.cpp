#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::dnn;

const String model = "res10_300x300_ssd_iter_140000_fp16.caffemodel"; // �ٿ���� ������ �� �ҷ�����
const String config = "deploy.prototxt"; // �ٿ���� ������ �� �ҷ�����
//const String model = "opencv_face_detector_uint8.pb";
//const String config = "opencv_face_detector.pbtxt";

int main() {
	VideoCapture cap(1);

	if (!cap.isOpened())
	{
		cerr << "camera open failed! " << endl;
		return -1;
	} // camera�� �������ϸ� ȭ�鿡 ��� �� ���α׷� ����

	Net net = readNet(model, config);


	if (net.empty())
	{
		cerr << "Net open failed! " << endl;
		return -1;
	} // Net�� ��ü ���� ���� ��  ȭ�鿡 ��� �� ���α׷� ����

	Mat frame, bin;
	Mat dst, dst_gray, dst_erode;
	while (true)
	{
		cap >> frame;
		if (frame.empty())
			break; // ī�޶��� �� �������� frame ������ ���� frame�� �޾� ���� ���ϸ� ���α׷� ����

		Mat blob = blobFromImage(frame, 1, Size(300, 300), Scalar(104, 177, 123));
		net.setInput(blob);
		Mat res = net.forward(); // frame ������ �̿��Ͽ� ��Ʈ��ũ �Է� ����� ���� ��Ʈ��ũ ���� ����� res��Ŀ� ����

		Mat detect(res.size[2], res.size[3], CV_32FC1, res.ptr<float>());

		for (int i = 0; i < detect.rows; i++)
		{
			float confidence = detect.at<float>(i, 2);
			if (confidence < 0.5)
				break; // ��� ��Ŀ��� �ŷڵ� ���� 0.5���� ������ ����

			int x1 = cvRound(detect.at<float>(i, 3) * frame.cols);
			int y1 = cvRound(detect.at<float>(i, 4) * frame.rows);
			int x2 = cvRound(detect.at<float>(i, 5) * frame.cols);
			int y2 = cvRound(detect.at<float>(i, 6) * frame.rows);
			// �� ���� �簢�� ������ ���� ��� ��ǥ(x1, y1)�� ���� �ϴ� ��ǥ(x2, y2)�� ��� 

			rectangle(frame, Rect(Point(x1, y1), Point(x2, y2)), Scalar(0, 255, 0));

			String label = format("Face: %4.3f", confidence);
			putText(frame, label, Point(x1, y1 - 1), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0));
			// frame ���󿡼� �� ���� ������ ��� �簢������ �׸��� �� �ŷڵ��� ��� //end of for
			if (confidence >= 0.5)
			{
				dst = frame(Rect(Point(x1, y1), Point(x2, y2))).clone();
				cvtColor(dst, dst_gray, COLOR_BGR2GRAY);
			}
		}
		if (!dst_gray.empty())
		{
			threshold(dst_gray, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
			if (bin.empty())
				break;

			erode(bin, dst_erode, Mat());
			imshow("erode", dst_erode);
		}
			//morphologyEx(frame, frame, MORPH_OPEN, Mat()); // ���� ���� ����
		
			
			imshow("frame", frame); // ȭ�鿡 ���
			
			if (waitKey(10) == 27)
				break;  // escŰ�� ������ ����
		} // end of while
		return 0;
} // end of main
