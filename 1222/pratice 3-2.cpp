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
	cout << "�簢���� ũ��� " << sq.getArea() << "�̴� " << endl;
}