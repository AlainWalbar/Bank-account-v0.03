#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account {
private:
	int m_accID;
	int m_balance;
	char* m_cusName;

public:
	Account(const Account& ref);
	Account(int ID, int balance, char* cName);
	~Account();
	int GetAccID(void) const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo(void) const;
};
#endif