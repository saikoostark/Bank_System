#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "BankAccount.h"
using namespace std;


class Client{
	protected:
	string name ;
	string address ;
	string number;
	int isBasic;
	
	public:
	Client(){};
	void set_name(string name );
	void set_address(string address );	
	void set_number(string number );
	void set_accType(int isBasic);
	
	string get_name( );
	string get_address();	
	string get_number();
	bool is_basic();
	string get_accType();
	
};


#endif
