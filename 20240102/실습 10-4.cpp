#include <iostream>
using namespace std;

template <class T>
bool search(T a, T b[], int n) {
	for (int i = 0; i < n; i++){
		if (b[i] == a)
			return true;
	}
		return false;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	if (search(100, x, 5))
		cout << "배열 100이 포함되어있다";
	else cout << "배열 100이 포함되어있지않다";
}