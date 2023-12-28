#include <iostream>
using namespace std;

class Rect;
bool equals(Rect r, Rect s); // 따로 함수 지정해 주어야함

class Rect
{
	int width, height;
public:
	Rect(int widht, int height) { this->width = width; this->height = height; }
	friend bool equals(Rect r, Rect s);
};
bool equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 3), b(3, 3);
	if (equals(a, b)) cout << "Equal" << endl;
	else cout << "False" << endl;
}