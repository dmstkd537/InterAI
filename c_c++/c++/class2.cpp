#include <iostream>
using namespace std;

class Rectagle				// Ŭ������ �����
{
public:
	int width;
	int height;
	int getArea();
};

int Rectagle::getArea()		// Ŭ������ �����
{
	return width * height;
}

int main() {

	Rectagle rect;
	rect.width = 50;		// �簢���� ����
	rect.height = 70;		// �簢���� ����
	cout << "�簢���� ������ : " << rect.getArea() << endl;
}