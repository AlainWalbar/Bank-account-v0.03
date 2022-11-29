#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H

#include "Account.h"
#include "SavingAccount.h"
#include "HighCreditAccount.h"
#include "BankCommon.h"

#include<iostream>

class AccountHandler {
private:
    Account* m_accArr[MAX_ACC_NUM];     //Account array
    int m_accNum;                       //# of accounts
    int GetAccIdx(int id) const;
public:
    AccountHandler();
    ~AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    void MakeSavingAccount(void);       //adding a make saving account
    void MakeHighCreditAccount(void);   //adding a make high credit account
};

#endif