#include <iostream>
using namespace std;

template <class T>
T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int a = 70, b = 80;
	char c = 'a', d = 'z';
	cout << "bigger(70,80)�� ����� " << bigger(a, b) << endl;
	cout << "bigger('a', 'z')�� ����� " << bigger(c, d) << endl;
}