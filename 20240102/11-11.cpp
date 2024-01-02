#include <iostream>
using namespace std;

class Point
{
	int x, y, z;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	friend istream& operator >> (istream& ins, Point& a);
	friend ostream& operator << (ostream& stream, Point a);
};

istream& operator >> (istream& ins, Point& a) {
	cout << "x ÁÂÇ¥>>";
	ins >> a.x;
	cout << "y ÁÂÇ¥>>";
	ins >> a.y;
	cout << "z ÁÂÇ¥>>";
	ins >> a.z;
	return ins;
}

ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << "," << a.z << ")";
	return stream;
}

int main() {
	Point p;
	cin >> p;
	cout << p;
}