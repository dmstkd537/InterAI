#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	string text;
	srand((unsigned)time(0));

	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�) ";

	while (true)
	{
		cout << ">>";
		getline(cin, text, '\n');
		if (text == "exit")
			break;
		if (text == "")
			continue;
		int size = text.length();
		int index = rand() % size;
		int c = rand() % 26;
		char changechar = 'a' + c;
		if (text[index] == 'a' + c)
			changechar = 'A' + c;
		text[index] = changechar;
		cout << text << endl;
	}
}