#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


#include<string>
#include "Client.h"
using namespace std;


class BankAccount {
	protected:
	string accountID ;
	double balance ;

	
	public:
	BankAccount(){};
	BankAccount(string ID , double balance );
	void set_ID(string ID);
	string get_ID();
	string get_balance();
	virtual int withdraw(double balance);
	virtual int deposit(double balance);

};


#endif
