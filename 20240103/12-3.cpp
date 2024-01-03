#include <iostream>
#include <fstream>
#include <cctype> // toupper �Լ��� ����ϱ� ���� ���
using namespace std;

int main() {
    const char* file = "c:\\windows\\system.ini";

    ifstream fin;
    fin.open(file, ios::in | ios::binary);
    if (!fin) {
        cout << "���� ���� ����";
        return 0;
    }

    int count = 0;
    char s[32];
    while (!fin.eof()) {
        fin.read(s, 32);
        int n = fin.gcount();

        // ���ڸ� �빮�ڷ� ��ȯ�Ͽ� ���
        for (int i = 0; i < n; ++i) {
            cout << static_cast<char>(toupper(s[i]));
        }

        count += n;
    }

    cout << "���� ����Ʈ ���� " << count << endl;
    fin.close();

    return 0;
}