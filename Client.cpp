#include "Client.h"




void Client::set_name(string name ){
	this->name = name;
}

void Client::set_address(string address ){
	this->address = address;
}

void Client::set_number(string number ){
	this->number = number;
}

void Client::set_accType(int isBasic){
	this->isBasic = isBasic;
}


string Client::get_name( ){
	return name;
}
string Client::get_address(){
		return address;
	}
	string Client::get_number(){
		return number;
	}
	
	
	bool Client::is_basic(){
		return isBasic;
	}
	
	string Client::get_accType(){
	if(isBasic == 1 )
	return "Basic";
	
	return "Saving ";
	}