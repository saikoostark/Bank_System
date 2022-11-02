#ifndef SAVING_BANK_ACCOUNT_H
#define SAVING_BANK_ACCOUNT_H

#include<iostream>
#include "BankAccount.h"
#include "Client.h"


class SavingBankAccount : public BankAccount {	
	public:
	SavingBankAccount(){};
	SavingBankAccount(string ID , double balance);
	int withdraw(double balance);
	int deposit(double balance);
	
};




#endif