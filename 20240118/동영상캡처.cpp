#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Point pt01d, pt02d;
Mat img;
Mat dst;
Mat frame, inversed;

int a, b, c, d;
void on_mouse(int event, int x, int y, int flags, void*);
void camera_in();
int main()
{
    camera_in();
}

void camera_in()
{
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return;
    }

    cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

    int frameWidth = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int frameHeight = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);

    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo("captured_video.avi", fourcc, fps, Size(frameWidth, frameHeight));

    if (!outputVideo.isOpened()) {
        cout << "Video file open failed!" << endl;
        return;
    }

    while (true) {
        cap >> frame;
        if (frame.empty())
            break;

        dst = frame(Rect(c, d, a, b));
        if (!dst.empty()) {
            imshow("dst", dst);
        }

        setMouseCallback("frame", on_mouse);

        imshow("frame", frame);

        outputVideo << frame;  // 현재 프레임을 비디오로 저장

        if (waitKey(10) == 27) // ESC key
            break;
    }

    destroyAllWindows();
}

void on_mouse(int event, int x, int y, int flags, void*) {

    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        pt01d = Point(x, y);
        cout << "EVENT_LBUTTONDOWN:" << x << ", " << y << endl;
        break;
    case EVENT_LBUTTONUP:

        pt02d = Point(x, y);
        if (pt01d.x > pt02d.x) {
            a = pt01d.x - pt02d.x;
            c = pt02d.x;
        }
        else {
            a = pt02d.x - pt01d.x;
            c = pt01d.x;
        }
        if (pt01d.y > pt02d.y) {
            b = pt01d.y - pt02d.y;
            d = pt02d.y;
        }
        else {
            b = pt02d.y - pt01d.y;
            d = pt01d.y;
        }
        dst = frame(Rect(c, d, a, b));

        imshow("dst", dst);

        // 이미지를 파일로 저장
        imwrite("captured_image.jpg", dst);
        cout << "Captured image saved as captured_image.jpg" << endl;

        break;
    default:
        break;
    }
}