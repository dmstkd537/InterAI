#include <iostream>
using namespace std;

class circle
{
public:
	int radius;
	double getArea();  // circle 선언부
};

double circle::getArea()
{
	return 3.14 * radius * radius;   //circle 구현부
}

int main() {

	circle donut;
	donut.radius = 1;				// donut 객체의 반지름을 1로 설정
	double area = donut.getArea(); // donut의 면적 알아내기
	cout << "donut의 면적은 : " << area << endl;

	circle pizza;
	pizza.radius = 30;								// pizza 객체의 반지름을 30으로 설정
	area = pizza.getArea();							// pizza 객체의 면적 알아내기
	cout << "donut의 면적은 : " << area << endl;

	circle sum;
	sum.radius = donut.radius * pizza.radius;
	area = sum.getArea();
	cout << "도넛과 피자의 곱은: " << area << endl;
}