#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Point pt01d, pt02d;
Mat img;
Mat dst;
Rect rect;

void on_mouse(int event, int x, int y, int flags, void*);

int main()
{
    // "lenna.bmp" 파일 열기
    img = imread("lenna.bmp");

    if (img.empty()) {
        cerr << "Image open failed!" << endl;
        return -1;
    }

    namedWindow("img");
    setMouseCallback("img", on_mouse);

    while (true) {
        imshow("img", img);

        if (waitKey(10) == 27) // ESC key
            break;
    }

    return 0;
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
            rect.width = pt01d.x - pt02d.x;
            rect.x = pt02d.x;
        }
        else {
            rect.width = pt02d.x - pt01d.x;
            rect.x = pt01d.x;
        }
        if (pt01d.y > pt02d.y) {
            rect.height = pt01d.y - pt02d.y;
            rect.y = pt02d.y;
        }
        else {
            rect.height = pt02d.y - pt01d.y;
            rect.y = pt01d.y;
        }

        // 드래그한 영역 캡처
        dst = img(rect);
        imshow("captured", dst);

        // 이미지를 파일로 저장
        imwrite("captured_image.jpg", dst);
        cout << "Captured image saved as captured_image.jpg" << endl;

        break;
    default:
        break;
    }
}