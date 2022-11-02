#include "SavingBankAccount.h"


//SavingBankAccount::SavingBankAccount(){
//	this->balance = this->minimunBalance ;
//}


SavingBankAccount::SavingBankAccount(string ID , double balance  ): BankAccount(ID , balance){
	if(balance >= 100)
	this->balance = balance ;
	else{
		cerr<< "you must entered value more than 100 in saving bank account\n";
		exit(0);
	}
}


int SavingBankAccount::withdraw(double balance){
	if(this->balance - balance < 1000)
	return 0;
	
	this->balance -= balance ;
	return 1 ; 
	
}


int SavingBankAccount::deposit(double balance){
	if(balance < 100){
	return 0 ; 
	}
	this->balance += balance ;
	return 1 ; 
	
}