#include "SavingAccount.h"

SavingAccount::SavingAccount(int ID, int balance, char* cName, int rate)
    : Account(ID, balance, cName), m_InterestRate{ rate }
{
}

void SavingAccount::Deposit(int money)
{
    Account::Deposit(money);
    Account::Deposit(money * (m_InterestRate / 100.0));
}