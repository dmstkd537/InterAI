#include <iostream>
using namespace std;

class circle
{
public:
	int radius;
	circle(); // 기본 생성자
	circle(int r); // 매개 변수가 있는 생성자
	double getArea();
};

circle::circle()
{
	radius = 1; // 반지름값 초기화
	cout << "반지름 " << radius << " 원 생성" << endl;
}
circle::circle(int r)
{
	radius = 30;
	cout << "반지름 " << radius << " 원 생성" << endl;
}
double circle::getArea() // class 구현부
{
	return 3.14 * radius * radius;
}

int main() {

	circle donut; // 매개 변수 없는 생성자 호출
	double area = donut.getArea();
	cout << "donut의 면적은 " << area << endl;

	circle pizza(30);
	area = pizza.getArea();
	cout << "pizza의 면적은 " << area << endl;
}