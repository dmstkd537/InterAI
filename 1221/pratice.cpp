#include <iostream>
#include <string>
using namespace std;

int main() {
	string song("lovesick girl"); // ���ڿ� song
	string black("black pink"); // ���ڿ� bp
	string singer;

	cout << song + "�� �θ� ������"; // +�� ���ڿ� ����
	cout << "(��Ʈ : ù���ڴ� " << black[0] << ")?"; // []������ ���

	getline(cin, singer); // ���ڿ� �Է�
	if (singer == black) // ���ڿ� ��
		cout << "�¾ҽ��ϴ�.";
	else
		cout << "Ʋ�Ƚ��ϴ�." + black + "�Դϴ�" << endl; // +�� ���ڿ� ����
}