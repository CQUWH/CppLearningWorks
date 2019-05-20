#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>
#include <vector>

// �˻�����
class Account {
private:
	// �˻�,�˻�����,����,���֤��,����,����Ƿ��,���ö��
	std::string account;
	bool islAccount;  // ����˻�Ϊtrue������˻�Ϊflase
	std::string name;
	std::string id;
	std::string password;
	double balance;   // ����˻����Ϊ����
	double reputation;

public:
	const std::string& getAccount() const {
		return account;
	}
	void setAccount(const std::string& account) {
		this->account = account;
	}
	const std::string& getId() const {
		return id;
	}
	void setId(const std::string& id) {
		this->id = id;
	}
	const std::string& getName() const {
		return name;
	}
	void setName(const std::string& name) {
		this->name = name;
	}
	const std::string& getPassword() const {
		return password;
	}
	void setPassword(const std::string& password) {
		this->password = password;
	}
	double getBalance() const {
		return balance;
	}
	void setBalance(double balance) {
		this->balance = balance;
	}
	bool isIslAccount() const {
		return islAccount;
	}
	void setIslAccount(bool islAccount) {
		this->islAccount = islAccount;
	}
	double getReputation() const {
		return reputation;
	}
	void setReputation(double reputation) {
		this->reputation = reputation;
	}
	void show();
};
#endif /* ACCOUNT_H_ */
