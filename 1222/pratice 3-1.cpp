#include <iostream>
using namespace std;

class circle
{
public:
	int radius;
	double getArea();
};

double circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	circle donut;
	donut.radius = 6;
	double area = donut.getArea();
	cout << "������ ������ " << area << "�̴� " << endl;

	circle pizza;
	pizza.radius = 15;
	area = pizza.getArea();
	cout << "������ ������ " << area << "�̴� " << endl;
}

