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
	cout << "도넛의 면적은 " << area << "이다 " << endl;

	circle pizza;
	pizza.radius = 15;
	area = pizza.getArea();
	cout << "피자의 면적은 " << area << "이다 " << endl;
}

