#include <iostream>
using namespace std;

class circle
{
public:
	int radius;
	circle(); // �⺻ ������
	circle(int r); // �Ű� ������ �ִ� ������
	double getArea();
};

circle::circle()
{
	radius = 1; // �������� �ʱ�ȭ
	cout << "������ " << radius << " �� ����" << endl;
}
circle::circle(int r)
{
	radius = 30;
	cout << "������ " << radius << " �� ����" << endl;
}
double circle::getArea() // class ������
{
	return 3.14 * radius * radius;
}

int main() {

	circle donut; // �Ű� ���� ���� ������ ȣ��
	double area = donut.getArea();
	cout << "donut�� ������ " << area << endl;

	circle pizza(30);
	area = pizza.getArea();
	cout << "pizza�� ������ " << area << endl;
}