#include<iostream>
#include<iomanip>
#include "BankApplication.h"

using namespace std;


void menu(){
	
	BankAppplication bank;	
	int choice ;
	
	cout<< "Welcome to FCAI Banking Application\n\n"
	       "1. Create a New Account\n"
	       "2. List Clients and Accounts\n"
	       "3. Withdraw Money\n"
	       "4. Deposit Money\n"
	       "Please Enter Choice =========> ";
	       cin >> choice;
	       if(choice ==  1){
	       	string name , address , phone ;
	       	int account_type ;
	       	double balance;
	       	cout<< "Please Enter Client Name =========> ";
	       	cin >> name ;
	       	cout<< "Please Enter Client Address =======> ";
	       	cin >> address;
	       	cout<< "Please Enter Client Phone =======> ";
	       	cin >> phone;
	       	cout<< "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
	       	cin>> account_type;
	       	cout<< "Please Enter the Starting Balance =========> ";
	       	cin >> balance;
		       if(bank.addClient(name , address , phone  , balance , account_type))
		       cout<< "An account was created with ID "<< bank.get_ID() << " and Starting Balance " << balance<<  " L.E.\n";
		       else
		       cout << "there are some wrong information you have entered\n";
	       }else if(choice ==  2){
	       	for(auto user : bank.listUsers()){
	       	cout<< "\n-------------------------------------------" << user[0] << "-------------------------------------------"
	       			<< "\nAddress: " << user[1] 
	       			<< "\nAccount ID : " << user[4] << " (" << user[3] << ")"
	       			<< "\nBalance: " << user[5]<< endl;
	       	}
	       }else if(choice == 3){
	       	string ID;
	       	cout<< "Please Enter Account ID (e.g., FCAI-015) =========> ";
	       	cin >> ID;
	       	
	       	auto user = bank.user_info(ID);
	       	if(user.size() == 0)
	       	cout<< "this ID " << ID << " doesn't exist\n";
	       	else{
	       		double balance ;
	       		cout<< "Account ID: " << user["id"]
	       		<< "\nAcocunt Type: " << user["type"]
	       		<< "\nBalance: " << user["balance"] 
	       		<< "\nPlease Enter The Amount to Withdraw =========> ";
	       		cin >> balance;
	       		if(bank.withdraw(ID , balance)){
	       			user = bank.user_info(ID);
	       			cout<< "Thank you\n"
	       			     	<<"Account ID: " << user["id"]
	       			     	 <<"\nNew Balance: " << user["balance"];
	       		}else{
	       			cout<< "\n sorry you have entered unavailabe amount";
	       		}
	       		
	       	}
	       }else if(choice == 4){
	       	string ID;
	       	cout<< "Please Enter Account ID (e.g., FCAI-015) =========> ";
	       	cin >> ID;
	       	
	       	auto user = bank.user_info(ID);
	       	if(user.size() == 0)
	       	cout<< "this ID " << ID << " doesn't exist\n";
	       	else{
	       		double balance ;
	       		cout<< "Account ID: " << user["id"]
	       		<< "\nAcocunt Type: " << user["type"]
	       		<< "\nBalance: " << user["balance"] 
	       		<< "Please Enter The Amount to deposit =========> ";
	       		cin >> balance;
	       		if(bank.deposit(ID , balance)){
	       			user = bank.user_info(ID);
	       			cout<< "Thank you\n"
	       			     	<<"Account ID: " << user["id"]
	       			     	 <<"\nNew Balance: " << user["balance"];
	       		}
	       		
	       	}
	       }
	  
	       
	  cout<< "\n\n";
}


int main(){
	
	while(1)
	menu();
	
	return 0 ;	
}