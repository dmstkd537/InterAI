#include <iostream>
using namespace std;

int big(int a, int b, int c) {
	if (a > b) return a;
	else if (a < b) return b;
	else return c;
}
int big(int a[], int size) {
	int res = a[0];
	for (int i = 1; i < size; i++)
		if (res < a[i]) res = a[i];
	return res;
}

int main() {
	int array[6] = { 3,5,300,60,30,50 };
	cout << big(30, 60, 50) << endl;
}