#include "cUI.h"
using namespace std;

void cUI::welcome(){
	cout << "*****************************" << endl;
	cout << "*                           *" << endl;
	cout << "*         WELCOME           *" << endl;
	cout << "* press <enter> to continue *" << endl;
	cout << "*         ... ...           *" << endl;
	cout << "*                           *" << endl;
	cout << "*****************************" << endl;
}

// ����˻��Ĳ�������
int cUI::menu1(){
	cout << "���˵�:" << endl;
	cout << "\t1 - �˻���Ϣ" << endl;
	cout << "\t2 - ȡ��" << endl;
	cout << "\t3 - ���" << endl;
	cout << "\t4 - ת��" << endl;
	cout << "\t5 - �޸�����" << endl;
	cout << "\t6 - �˿�" << endl;
	cout << "������������: ";
	int input;
	cin >> input;
	return input;
}

// ���ÿ��˻��Ĳ�������
int cUI::menu2(){
	cout << "���˵�:" << endl;
	cout << "\t1 - �˻���Ϣ" << endl;
	cout << "\t2 - ȡ��" << endl;
	cout << "\t3 - ����" << endl;
	cout << "\t4 - ת��" << endl;
	cout << "\t5 - �޸�����" << endl;
	cout << "\t6 - �˿�" << endl;
	cout << "������������: ";
	int input;
	cin >> input;
	return input;
}

void cUI::load(int number, vector<vector<string>> &users, Account *ac){
	cout << "           ��¼��...        " << endl;
	string account;
	while (true){
		cout << "�������˺�: ";
		cin >> account;
		for (int i = 1; i < number; i++){
			if (users[i][0] == account){
				ac->setAccount(users[i][0]);
				ac->setIslAccount(users[i][1] == "lAccount");
				ac->setName(users[i][2]);
				ac->setId(users[i][3]);
				ac->setPassword(users[i][4]);
				stringstream ss1;
				ss1 << users[i][5];
				double balance;
				ss1 >> balance;
				ac->setBalance(balance);
				stringstream ss2;
				ss2 << users[i][6];
				double Reputation;
				ss2 >> Reputation;
				ac->setReputation(Reputation);
				return;
			}
		}
		cout << "�˺������������������" << endl;
	}
}

bool cUI::password(const string& password){
	cout << "           ��¼��...        " << endl;
	int count = 0;
	string input;
	cout << "����������: ";
	for (int i = 0; i < 3; i++){
		cin >> input;
		if (input == password){
			return true;
		}
		else{
			cout << "�������" << endl;
			count++;
			if (count < 3){
				cout << "����" << 3-count << "���������"<< endl;
				cout << "����������: ";
			}

		}
	}
	if(count >= 3){
		cout << "�˺��ѱ����ᣬ��������������..." << endl;
		return false;
	}
	return false;
}

double cUI::getMoney(const int n, Account &account){
	double money;
	int temp;
	switch (n){
	case 1:  // ȡ��, ���������Ҳ��������
		while (true){
			cout << "������ȡ���";
			cin >> money;
			temp = int(money);
			if (money - temp != 0 || temp % 100 != 0 || money > 3000 || money < 100)
			{
				cout << "ȡ����ֻ��Ϊ100-3000�����٣�����������" << endl;
				continue;
			}
			if (account.isIslAccount() && (money - account.getBalance()) > account.getReputation()){
				cout << "������͸֧��ȣ�����������" << endl;
				continue;
			}
			if (!account.isIslAccount() && money > account.getBalance()){
				cout << "���㣬����������" << endl;
				continue;
			}
			break;
		}
		break;
	case 2:  // ��� ����
		while (true){
			cout << "��Ͷ�ң�";
			cin >> money;
			if (money <= 0){
				cout << "��������������������" << endl;
				continue;
			}
			if (account.isIslAccount() && -account.getBalance() < money){
				cout << "������ܳ���Ƿ�����������" << endl;
				continue;
			}
			break;
		}
		break;
	case 3:  // ת��
		while (true){
			cout << "������ת�˽��:";
			cin >> money;
			if (money <= 0){
				cout << "��������������������" << endl;
				continue;
			}
			if (account.isIslAccount() && (money - account.getBalance()) > account.getReputation()){
				cout << "������͸֧��ȣ�����������" << endl;
				continue;
			}
			if (!account.isIslAccount() && money > account.getBalance()){
				cout << "���㣬����������" << endl;
				continue;
			}
			break;
		}
		break;
	}
	return money;
}

void cUI::isSuccess(bool success){
	if (success)
		cout << "�����ɹ�" << endl;
	else
		cout << "�����쳣���������й�����Ա��ϵ" << endl;
	cout << "press <enter> to quit" << endl;
	cin.sync();
	cin.get();
}
