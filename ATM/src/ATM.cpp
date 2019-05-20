#include "ATM.h"
using namespace std;

void ATM::setAccount(Account *account) {
	this->account = account;
}

// ���  /  ����
bool ATM::Deposit(double money) {
	vector<vector<string>> &file = this->file->getFile();
	this->account->setBalance(this->account->getBalance() + money);
	for (int i = 1; i < this->file->getRow(); i++) {
		if (this->account->getAccount() == file[i][0]) {
			stringstream ss;
			ss << this->account->getBalance();
			ss >> file[i][5];
			this->file->saveCSV();   // �����ļ�
			if (account->isIslAccount()) {
				Record(3, money);
				return true;
			}
			Record(1, money);  // ���������¼
			return true;
		}
	}
	return false;
}

// ȡ��  / ���
bool ATM::Withdrow(int money) {
	vector<vector<string>> &file = this->file->getFile();
	this->account->setBalance(this->account->getBalance() - money);
	for (int i = 1; i < this->file->getRow(); i++) {
		if (this->account->getAccount() == file[i][0]) {
			stringstream ss;
			ss << this->account->getBalance();
			ss >> file[i][5];
			this->file->saveCSV();   // �����ļ�
			Record(2, money);   	 // ���������¼
			return true;
		}
	}
	return false;
}

// ת��
bool ATM::Tansfer(double money, string other) {
	vector<vector<string>> &file = this->file->getFile();
	this->account->setBalance(this->account->getBalance() - money);
	for (int i = 1; i < this->file->getRow(); i++) {
		if (this->account->getAccount() == file[i][0]) {
			stringstream ss;
			ss << this->account->getBalance();
			ss >> file[i][5];
		}
		if (other == file[i][0]) {
			double otherMoney;
			stringstream s1;
			s1 << file[i][5];
			s1 >> otherMoney;
			otherMoney += money;
			stringstream s2;
			s2 << otherMoney;
			s2 >> file[i][5];
		}
	}
	this->file->saveCSV();   // �����ļ�
	Record(4, money, other);  // ���������¼
	return true;
}

// ��ѯ���  / Ƿ������ö��
void ATM::show() {
	this->account->show();
}

// �޸�����
void ATM::changePassword(std::string password) {
	vector<vector<string>> &file = this->file->getFile();
	for (int i = 1; i < this->file->getRow(); i++) {
		if (this->account->getAccount() == file[i][0]) {
			file[i][4] = password;
			this->file->saveCSV();
		}
	}
}

void ATM::Record(int number, double money, string other) {
	ofstream out_file;
	out_file.open("E:\\cppworkspace\\ATM\\files\\Record.txt", ios::app); // ���ļ���׷�Ӳ�����¼
	out_file << endl;
	out_file << "ʱ�䣺" << Time::getTime() << endl;
	out_file << "�˻���" << this->account->getAccount() << endl;
	out_file << "�������ͣ�";
	switch (number) {
	case 1:
		out_file << "���" << endl;
		out_file << "���飺" << "����" << money << "Ԫ" << endl;
		break;
	case 2:
		out_file << "ȡ��" << endl;
		out_file << "���飺" << "ȡ��" << money << "Ԫ" << endl;
		break;
	case 3:
		out_file << "����" << endl;
		out_file << "���飺" << "����" << money << "Ԫ" << endl;
		break;
	case 4:
		out_file << "ת��" << endl;
		out_file << "���飺" << "ת��" << money << "Ԫ" << endl;
		out_file << "�տ��˻���" << other << endl;
		break;
	}
	if (account->isIslAccount()) {
		out_file << "Ƿ�" << -this->account->getBalance() << endl;
		out_file << "�����ȣ�" << this->account->getReputation() << endl;
	} else {
		out_file << "��" << this->account->getBalance() << endl;
	}
}
