#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void on_level_change(int pos, void* userdata);

int main() {

    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    Mat::zeros(400, 400, CV_8UC1);

    if (src.empty()) {
        cerr << "image load failed!" << endl;
        return -1; // 이미지 로드에 실패한 경우 프로그램 종료
    }

    imshow("src", src);
    namedWindow("src");

    namedWindow("dst");
    createTrackbar("level", "dst", 0, 16, on_level_change, (void*)&src);

    Mat dst;
    for (int sigma = 1; sigma <= 8; sigma++) {

        GaussianBlur(src, dst, Size(), (double)sigma);

        String text = format("sigma = %d", sigma);
        putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();
    }

    for (int sigma = 1; sigma < 5; sigma++) {
        Mat blurred;
        GaussianBlur(src, blurred, Size(), sigma);

        float alpha = 1.f;
        Mat dst = (1 + alpha) * src - alpha * blurred;

        String desc = format("sigma: %d", sigma);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();

        imwrite("rose.bmp", dst);
        cout << "sigma" << sigma << endl;
    }

    destroyAllWindows();
    return 0;
} // end of main

void on_level_change(int pos, void* userdata) {

    Mat src = *(Mat*)userdata;
    src.setTo(pos * 16);

}