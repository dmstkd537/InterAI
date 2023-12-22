#include <iostream>
using namespace std;

class circle
{
public:
	int radius;
	circle();
	circle(int r);
	double getArea();

};
circle::circle() {
	radius = 1;
	cout << "면적은 " << radius << " 원 생성" << endl;
}
circle::circle(int r) {
	radius = r;
	cout << "면적은 " << radius << " 원 생성" << endl;
}
double circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	circle donut;
	double area = donut.getArea();
	cout << "donut의 면적은 " << area << endl;

	circle pizza(50);
	area = pizza.getArea();
	cout << "pizza의 면적은 " << area << endl;
}