#include <iostream>
using namespace std;

int main() {
	cout << "주소는?>>";

	char address[11];
	cin >> address;

	cout << "이름은?>>";

	char name[10];
	cin >> name;

	cout << "나이는?>>";
	char age[3];
	cin >> age;

	cout << "주소는 " << address;
	cout << "이름은 " << name;
	cout << "나이는 " << age << "세";
}