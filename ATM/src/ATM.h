#ifndef ATM_H_
#define ATM_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Time.h"
#include "Account.h"
#include "CSV.h"

class ATM {
private:
	CSV *file;
	Account *account;  // ָ��ǰ�������˻��Ļ���ָ��
public:
	ATM(CSV *file){
		this->file = file;
		this->account = NULL;
	}
	// �����˻�
	void setAccount(Account *account);
	// ���  / ����
	bool Deposit(double money);
	// ȡ��  / ���
	bool Withdrow(int money);
	// ת��
	bool Tansfer(double money, std::string other);
	// ��ѯ���  / Ƿ������ö��
	void show();
	// �޸�����
	void changePassword(std::string password);
	// ���������¼
	void Record(int number, double money, std::string other="");
};

#endif /* ATM_H_ */
