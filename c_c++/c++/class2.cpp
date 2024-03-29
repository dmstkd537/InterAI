#include <iostream>
using namespace std;

class Rectagle				// 클래스의 선언부
{
public:
	int width;
	int height;
	int getArea();
};

int Rectagle::getArea()		// 클래스의 선언부
{
	return width * height;
}

int main() {

	Rectagle rect;
	rect.width = 50;		// 사각형의 넓이
	rect.height = 70;		// 사각형의 높이
	cout << "사각형의 면적은 : " << rect.getArea() << endl;
}