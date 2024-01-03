#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin;
	fin.open("c:\\c++\\student.txt");
	if (!fin) { //파일 열기 실패
		cout << "파일을 열수 없다";
		return 0;
	}
	char name[10], dept[20];
	int sid;

	fin >> name;
	fin >> sid;
	fin >> dept;

	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;

	fin.close();
}