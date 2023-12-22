#include <iostream>
using namespace std;

class square
{
public:
	int width;
	int height;
	int getArea();
};

int square::getArea() {
	return width * height / 2;
}

int main() {
	square sq;
	sq.width = 5;
	sq.height = 3;
	cout << "사각형의 크기는 " << sq.getArea() << "이다 " << endl;
}