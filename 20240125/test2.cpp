#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::dnn;

const String model = "res10_300x300_ssd_iter_140000_fp16.caffemodel"; // 다운받은 딥러닝 모델 불러오기
const String config = "deploy.prototxt"; // 다운받은 딥러닝 모델 불러오기
//const String model = "opencv_face_detector_uint8.pb";
//const String config = "opencv_face_detector.pbtxt";

int main() {
	VideoCapture cap(1);

	if (!cap.isOpened())
	{
		cerr << "camera open failed! " << endl;
		return -1;
	} // camera를 읽지못하면 화면에 출력 후 프로그램 종료

	Net net = readNet(model, config);


	if (net.empty())
	{
		cerr << "Net open failed! " << endl;
		return -1;
	} // Net을 객체 생성 실패 시  화면에 출력 후 프로그램 종료

	Mat frame, bin;
	Mat dst, dst_gray, dst_erode;
	while (true)
	{
		cap >> frame;
		if (frame.empty())
			break; // 카메라의 매 프레임을 frame 변수에 저장 frame을 받아 오지 못하면 프로그램 종료

		Mat blob = blobFromImage(frame, 1, Size(300, 300), Scalar(104, 177, 123));
		net.setInput(blob);
		Mat res = net.forward(); // frame 영상을 이용하여 네트워크 입력 블롭을 설정 네트워크 실행 결과를 res행렬에 저장

		Mat detect(res.size[2], res.size[3], CV_32FC1, res.ptr<float>());

		for (int i = 0; i < detect.rows; i++)
		{
			float confidence = detect.at<float>(i, 2);
			if (confidence < 0.5)
				break; // 결과 행렬에서 신뢰도 값이 0.5보다 작으면 무시

			int x1 = cvRound(detect.at<float>(i, 3) * frame.cols);
			int y1 = cvRound(detect.at<float>(i, 4) * frame.rows);
			int x2 = cvRound(detect.at<float>(i, 5) * frame.cols);
			int y2 = cvRound(detect.at<float>(i, 6) * frame.rows);
			// 얼굴 검출 사각형 영역의 좌측 상단 좌표(x1, y1)과 우측 하단 좌표(x2, y2)를 계산 

			rectangle(frame, Rect(Point(x1, y1), Point(x2, y2)), Scalar(0, 255, 0));

			String label = format("Face: %4.3f", confidence);
			putText(frame, label, Point(x1, y1 - 1), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0));
			// frame 영상에서 얼굴 검출 영역을 녹색 사각형으로 그리고 얼굴 신뢰도를 출력 //end of for
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
			//morphologyEx(frame, frame, MORPH_OPEN, Mat()); // 열기 연산 수행
		
			
			imshow("frame", frame); // 화면에 출력
			
			if (waitKey(10) == 27)
				break;  // esc키를 누르면 종료
		} // end of while
		return 0;
} // end of main
