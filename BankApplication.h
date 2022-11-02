#ifndef BANK_APPLICATION_H
#define BANK_APPLICATION_H

#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<sstream>
#include "BankAccount.h"
#include "SavingBankAccount.h"
#include "Client.h"

using namespace std;

class BankAppplication {
	
	private:
	void create_data();
	void set_data();
	void get_data();
	vector<pair<Client , BankAccount*>> users;
	
	public:
	BankAppplication();
	bool addClient(string name , string address , string number ,  double balance , int isBasic);
	vector<vector<string>> listUsers();
	void show_table();
	string get_ID();
	map<string , string> user_info(string ID);
	bool withdraw(string accountID , double balance);
	bool deposit(string accountID , double balance);
};




#endif