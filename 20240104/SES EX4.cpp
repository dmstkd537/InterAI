#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int Name_len = 20;

void showmenu(); // 메뉴 보기
void accountinfo(); // 계좌 조회
void depositmoney(); // 입금
void withdrawmoney(); // 출금

enum { make	 = 1, deposit , withdraw, Inquire, ext};

class BankAccount
{
	int accID; // 계좌번호
	int balance; // 금액
	char* cusName; // 고객명
public:
	BankAccount(int ID, int money, char* name) : accID(ID), balance(money) {
		cusName = new char[strlen(name) + 1];
		strcpy_s(cusName, strlen(name) + 1, name);
	}
	int getaccountinfo() { return accID; }

	void Deposit(int money) {
		balance += money;
	}
	
	int withdraw(int money) {
		if (balance < money) {
			return 0;
		}
		balance -= money;
		return money;
	}

	void accountinfo() {
		cout << "계좌 ID " << accID << endl;
		cout << "이   름" << cusName << endl;
		cout << "잔   액" << balance << endl;
	}

	~BankAccount() {
		delete[] cusName;
	}
};

BankAccount* accArr[100];
int accNum = 0;

int main() {
	int choice;
	while (1)
	{
		showmenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case deposit:
			depositmoney();
			break;
		case withdraw:
			withdrawmoney();
			break;
		case Inquire:
			accountinfo();
			break;
		case ext:
			for (int i = 0; i < accNum; i++)
			{
				delete accArr[i];
			} return 0;
		default: cout << "잘못된 선택입니다" << endl;
		}
	} return 0;
}

void showmenu() {
	cout << "------menu------" << endl;
	cout << "1. 입  금" << endl;
	cout << "2. 출  금" << endl;
	cout << "3. 계좌정보" << endl;
	cout << "4. 프로그램 종료" << endl;
}

void depositmoney() {
	int money;
	int id;

	cout << "[입  금]" << endl;
	cout << "계좌ID"; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccountinfo() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금 완료" << endl;
			return;
		}
	} cout << "유효하지 않은 ID입니다." << endl;
}
void withdrawmoney() {
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌 ID"; cin >> id;
	cout << "출금액"; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccountinfo() == id)
		{
			if (accArr[i]->withdraw(money) == 0)
			{
				cout << "잔액 부족" << endl;
				return;
			}
			cout << "출금 완료" << endl;
			return;
		}
	} cout << "유효하지 않는 ID 입니다" << endl;
}
void accountinfo() {
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->accountinfo();
		cout << endl;
	}
}