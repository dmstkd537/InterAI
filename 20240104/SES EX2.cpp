#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin;
	fin.open("c:\\windows\\temp\\php.ini");
	if (!fin) {
		cout << "파일을 열 수 없다.";
		return 0;
	}
	char str[] = "1521";
	char* ptr = strstr(str, "1521");
	if (ptr) {
		strncpy(ptr, "3306", 4);
			puts(str);
	}
	char str2[] = "3306";
	char* ptr2 = strstr(str2, "3306");
	if (ptr2) {
		strncpy(ptr2, "1521", 4);
		puts(str2);
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