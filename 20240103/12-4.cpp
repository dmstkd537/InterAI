#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* firstFile = "c:\\c++\\student.txt";
	const char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app); // 쓰기 모드로 파일 열기
	if (!fout) {
		cout << firstFile << " 열기 오류";
		return 0;
	}

	fstream fin(secondFile, ios::in);			  // 읽기 모드로 파일 열기
	if (!fin)
	{
		cout << secondFile << " 열기 오류";
	}

	int c;
	while (c = fin.get() != EOF)
	{
		fout.put(c);
	}

	fin.close();
	fout.close();
}