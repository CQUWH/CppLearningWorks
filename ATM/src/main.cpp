//============================================================================
// Name        : ATM.cpp
// Author      : Bully
// Version     : 1.0
// Copyright   :
// Description : ģ��ATM, Ansi-style
//============================================================================

#include <iostream>
#include <windows.h>
#include <vector>
#include "ATM.h"
#include "Account.h"
#include "CSV.h"
#include "cUI.h"
using namespace std;

int main() {
	while(true){
		CSV accountlist;
		accountlist.openFile("E:\\cppworkspace\\ATM\\files\\Account.csv");
		ATM atm(&accountlist);
		Account account;
		int number = accountlist.getRow();  // �˺ŵĸ���
		cUI::welcome();
		cin.get();
		cUI::load(number, accountlist.getFile(), &account);
		bool pass = cUI::password(account.getPassword());
		if(!pass)   // ������֤ûͨ��
		{
			Sleep(3000);
			cout << endl;
			cin.sync();
			continue;
		}
		atm.setAccount(&account);
		while(true){
			int input;
			if (account.isIslAccount()){
				input = cUI::menu2();
			}
			else{
				input = cUI::menu1();
			}
			if (input == 6){
				cout << "�˿��ɹ�����������������..." << endl;
				cout << endl;
				cin.sync();
				Sleep(3000);
				break;
			}
			int money;
			bool success;
			string newpassword1;
			string newpassword2;
			string other1;
			string other2;
			switch(input){
				case 1:
					atm.show();
					cout << "press <enter> to quit" << endl;
					cin.sync();
					cin.get();
					break;
				case 2:
					money = cUI::getMoney(1, account);
					success = atm.Withdrow(money);
					cUI::isSuccess(success);
					break;
				case 3:
					money = cUI::getMoney(2, account);
					success = atm.Deposit(money);
					cUI::isSuccess(success);
					break;
				case 4:
					money = cUI::getMoney(3, account);
					cout << "�������տ��˻�: ";
					cin >> other1;
					cout << "���ٴ�����ȷ��: ";
					cin >> other2;
					if (other1 == other2){
						success = atm.Tansfer(money, other1);
						cUI::isSuccess(success);
					}
					else{
						cout << "�����˻���һ�£�ת��ʧ��" << endl;
						cout << "press <enter> to quit" << endl;
						cin.sync();
						cin.get();
					}
					break;
				case 5:
					cout << "������������: ";
					cin >> newpassword1;
					cout << "���ٴ�����ȷ��: ";
					cin >> newpassword2;
					if (newpassword1 == newpassword2){
						atm.changePassword(newpassword2);
						cout << "�ɹ��޸�����" << endl << endl;
					}
					else
						cout << "�������벻һ�£��޸�����ʧ��" << endl << endl;
					break;
				default:
					cout << "�������" << endl;
			}
		}
	}
	return 0;
}
