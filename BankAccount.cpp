#include "BankAccount.h"


//BankAccount::BankAccount(){
//	this->balance = 0 ;
//}

BankAccount::BankAccount(string ID , double balance ){
	this->accountID = ID;
	this->balance = balance ;
}


int BankAccount::withdraw(double balance){
	if(this->balance < balance)
	return 0;
	
	this->balance -= balance ;
	return 1 ; 
	
}


int BankAccount::deposit(double balance){
	this->balance += balance ;
	return 1 ; 
	
}


void BankAccount::set_ID(string ID){
	this->accountID = ID;
	
}

	string BankAccount::get_ID(){
		return accountID;
	}
	string BankAccount::get_balance(){
		return to_string(balance);
	}