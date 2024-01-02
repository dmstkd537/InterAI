#include <iostream>
using namespace std;

class point
{
	int x, y;
public:
	point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend ostream& operator << (ostream& stream, point a);
};

// << 연산자 함수
ostream& operator << (ostream& stream, point a) {
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	point p(3, 4);
	cout << p << endl;

	point q(1, 100), r(2, 200);
	cout << q << r << endl;
}