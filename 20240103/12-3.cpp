#include <iostream>
#include <fstream>
#include <cctype> // toupper 함수를 사용하기 위한 헤더
using namespace std;

int main() {
    const char* file = "c:\\windows\\system.ini";

    ifstream fin;
    fin.open(file, ios::in | ios::binary);
    if (!fin) {
        cout << "파일 열기 오류";
        return 0;
    }

    int count = 0;
    char s[32];
    while (!fin.eof()) {
        fin.read(s, 32);
        int n = fin.gcount();

        // 문자를 대문자로 변환하여 출력
        for (int i = 0; i < n; ++i) {
            cout << static_cast<char>(toupper(s[i]));
        }

        count += n;
    }

    cout << "읽은 바이트 수는 " << count << endl;
    fin.close();

    return 0;
}