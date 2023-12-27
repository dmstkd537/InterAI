#include <iostream>
using namespace std;

int sum(int a, int b) {
	int s = 0;
	for (int i = a; i <= b; i++)
		s += i;
	return s;
}
int sum(int a) {
	int s = 0;
	for (int i = 0; i <= a; i++)
		s += i;
	return s;
}

int main() {
	cout << sum(5, 1) << endl;
	cout << sum(50) << endl;
	cout << sum(51) << endl;
}