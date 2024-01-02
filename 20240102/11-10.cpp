#include <iostream>
#include <string>
using namespace std;

class Book
{
	string title;
	string press;
	string author;
public:
	Book(string title = "", string press = "", string author = "") {
		this->title = title;
		this->press = press;
		this->author = author;
	}
	friend ostream& operator << (ostream& stream, Book b);

};


// 연산자 함수
ostream& operator << (ostream& stream, Book b) {
	stream << b.title << "," << b.press << "," << b.author;
	return stream;
}

int main() {
	Book book("사느냐 죽느냐", "한국출판사", "에리히프롬"); // Book 클래스 생성
	cout << book; // book 객체 화면 출력
}