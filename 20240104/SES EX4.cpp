#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int Name_len = 20;

void showmenu(); // �޴� ����
void accountinfo(); // ���� ��ȸ
void depositmoney(); // �Ա�
void withdrawmoney(); // ���

enum { make	 = 1, deposit , withdraw, Inquire, ext};

class BankAccount
{
	int accID; // ���¹�ȣ
	int balance; // �ݾ�
	char* cusName; // ����
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
		cout << "���� ID " << accID << endl;
		cout << "��   ��" << cusName << endl;
		cout << "��   ��" << balance << endl;
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
		cout << "���� : ";
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
		default: cout << "�߸��� �����Դϴ�" << endl;
		}
	} return 0;
}

void showmenu() {
	cout << "------menu------" << endl;
	cout << "1. ��  ��" << endl;
	cout << "2. ��  ��" << endl;
	cout << "3. ��������" << endl;
	cout << "4. ���α׷� ����" << endl;
}

void depositmoney() {
	int money;
	int id;

	cout << "[��  ��]" << endl;
	cout << "����ID"; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccountinfo() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�Ա� �Ϸ�" << endl;
			return;
		}
	} cout << "��ȿ���� ���� ID�Դϴ�." << endl;
}
void withdrawmoney() {
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "���� ID"; cin >> id;
	cout << "��ݾ�"; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->getaccountinfo() == id)
		{
			if (accArr[i]->withdraw(money) == 0)
			{
				cout << "�ܾ� ����" << endl;
				return;
			}
			cout << "��� �Ϸ�" << endl;
			return;
		}
	} cout << "��ȿ���� �ʴ� ID �Դϴ�" << endl;
}
void accountinfo() {
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->accountinfo();
		cout << endl;
	}
}