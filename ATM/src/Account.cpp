#include "Account.h"
using namespace std;

void Account::show(){
	if(this->islAccount){
		cout << "\n\t�˻�����: " << "����ʻ�" << endl;
		cout << "\t��ǰǷ��: " << -(this->balance) << endl;
		cout << "\t����������: " << this->reputation << endl;
	}
	else{
		cout << "\n\t�˻�����: " << "����ʻ�" << endl;
		cout << "\t��ǰ���: " << this->balance << endl;
	}

}
