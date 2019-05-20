#ifndef CUI_H_
#define CUI_H_
#include <iostream>
#include <vector>
#include <sstream>
#include "Account.h"

class cUI {
public:
	static void welcome();
	static int menu1();
	static int menu2();
	static void load(int number, std::vector<std::vector<std::string>> &, Account *);
	static bool password(const std::string &);
	// ��ȡ����֤�û�����Ǯ������Ч��, ����������Ч�󷵻�Ǯ��
	static double getMoney(const int n, Account &account);
	static void isSuccess(bool success);
};
#endif /* CUI_H_ */
