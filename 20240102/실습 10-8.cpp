#include <iostream>
using namespace std;

class Comparable
{
public:
	virtual bool operator > (Comparable& op2) = 0;
	virtual bool operator < (Comparable& op2) = 0;
	virtual bool operator == (Comparable& op2) = 0;
};

class circle : public Comparable
{
	int radius;
public:
	circle(int radius = 1) { this->radius = radius; }
	int getradius() { return radius; }

	virtual bool operator > (Comparable& op2) {
		circle* p = (circle*)&op2;
		if (radius > p->radius) return true;
		return false;
	}

	virtual bool operator < (Comparable& op2) {
		circle* p = (circle*)&op2;
		if (radius < p->radius) return true;
		return false;
	}

	virtual bool operator == (Comparable& op2) {
		circle* p = (circle*)&op2;
		if (radius == p->radius) return true;
		return false;
	}
};

template <class T>
T bigger(T a, T b) {   // 두 개의 매개 변수를 비교하여 큰 값을 리턴
	if (a > b) return a;
	else return b;
}

int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getradius() << endl;
}