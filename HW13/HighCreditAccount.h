#ifndef HIGH_CREDIT_ACCOUNT
#define HIGH_CREDIT_ACCOUNT
#include "SavingAccount.h"

class HighCreditAccount : public SavingAccount {
private:
	int m_SpecialRate;
public:
	HighCreditAccount(int ID, int balance, char* cname, int rate, int special);
	virtual void Deposit(int money);
};

#endif