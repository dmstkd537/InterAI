#include <iostream>
using namespace std;

class circle
{
public:
	int radius;
	double getArea();  // circle �����
};

double circle::getArea()
{
	return 3.14 * radius * radius;   //circle ������
}

int main() {

	circle donut;
	donut.radius = 1;				// donut ��ü�� �������� 1�� ����
	double area = donut.getArea(); // donut�� ���� �˾Ƴ���
	cout << "donut�� ������ : " << area << endl;

	circle pizza;
	pizza.radius = 30;								// pizza ��ü�� �������� 30���� ����
	area = pizza.getArea();							// pizza ��ü�� ���� �˾Ƴ���
	cout << "donut�� ������ : " << area << endl;

	circle sum;
	sum.radius = donut.radius * pizza.radius;
	area = sum.getArea();
	cout << "���Ӱ� ������ ����: " << area << endl;
}