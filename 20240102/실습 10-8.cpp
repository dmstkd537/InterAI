#include <iostream>
using namespace std;

class comparable
{
public:
	virtual bool operator > (comparable& op2) = 0;
	virtual bool operator < (comparable& op2) = 0;
	virtual bool operator == (comparable& op2) = 0;
};

class Circle : public comparable {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }

	virtual bool operator > (comparable& op2) {
		Circle* p = (Circle*)&op2;
		if (radius > p->radius) return true;
		return false;
	}
	virtual bool operator > (comparable& op2) {
		Circle* p = (Circle*)&op2;
		if (radius < p->radius) return true;
		return false;
	}
	virtual bool operator > (comparable& op2) {
		Circle* p = (Circle*)&op2;
		if (radius == p->radius) return true;
		return false;
	}
};

int main(){}