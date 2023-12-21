#include <iostream>
#include <string>
using namespace std;

int main() {
	string song("lovesick girl"); // 문자열 song
	string black("black pink"); // 문자열 bp
	string singer;

	cout << song + "를 부른 가수는"; // +로 문자열 연결
	cout << "(힌트 : 첫글자는 " << black[0] << ")?"; // []연산자 사용

	getline(cin, singer); // 문자열 입력
	if (singer == black) // 문자열 비교
		cout << "맞았습니다.";
	else
		cout << "틀렸습니다." + black + "입니다" << endl; // +로 문자열 연결
}