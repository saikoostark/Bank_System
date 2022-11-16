#include "BankApplication.h"


//BankAppplication::BankApplication(){}


void BankAppplication::create_data(){
	
	ifstream file;
	file.open("Bank_Data.csv");
	
	if(!file){
	file.close();
	ofstream file("Bank_Data.csv");
	file.close();
	}
	
}


void BankAppplication::set_data(){
	
	ofstream file("Bank_Data.csv");
	
	
	for(int i = 0 ; i < users.size() ; i++){
		file <<users[i].second->get_ID()<<',';
		file <<users[i].second->get_balance()<<',';
		file << users[i].first.get_name()<< ',';
		file << users[i].first.basic_saving()<< ',';
		file << users[i].first.get_address()<< ',';
		file << users[i].first.get_number()<< '\n';		
	}

	file.close();
	
}


void BankAppplication::get_data(){
ifstream file;
	file.open("Bank_Data.csv");
	string line = "";
	string buffer;
	users.clear();
	while(getline(file , line)){
		istringstream ss(line);
		Client user;
		
		string name , address , number , isBasic , ID , balance;
		getline(ss , ID , ',');
		getline(ss , balance , ',');
		getline(ss , name , ',');
		getline(ss , isBasic , ',');
		getline(ss , address , ',');
		getline(ss , number , ',');
		
		int basic = stoi(isBasic);
		double Balance = stod(balance);
		
		user.set_name(name);
		user.set_address(address);
		user.set_number(number);
		user.set_accType(basic);
		
		
		
		if(basic == 1){
			users.push_back({user , new BankAccount(ID , Balance)});
		}
		else if(basic == 2 ){ 
			users.push_back({user , new SavingBankAccount(ID , Balance)});
		}	
	}		
	
}



BankAppplication::BankAppplication(){
	
	create_data();
	get_data();
}


bool BankAppplication::addClient(string name , string address , string number  , double balance , int isBasic){
		Client user;
		
		string ID = "FCAI-" + to_string(users.size()+1);
		user.set_name(name);
		user.set_address(address);
		user.set_number(number);
		user.set_accType(isBasic);
		
		if(isBasic == 1){
			users.push_back({user , new BankAccount(ID , balance)});
		}
		else if(isBasic ==  2 ){
			
			if(balance < 1000)
			return 0 ; 
			users.push_back({user , new SavingBankAccount(ID , balance)});
		}else{
			return 0 ;
		}
	
	
	set_data();
	return 1;
}




map<string , string> BankAppplication::user_info(string ID){
	map<string , string> user;
	
	for(int i = 0 ; i < users.size() ; i++){
		if(users[i].second->get_ID() == ID){
			user["id"] = users[i].second->get_ID();
			user["balance"]  = users[i].second->get_balance();
			user["type"] = users[i].first.get_accType();
		}
	}
	
	return user ;
}


 vector<vector<string>> BankAppplication::listUsers(){
	vector<vector<string>> list(users.size());

	for(int i = 0 ; i < users.size() ; i++){
		list[i].push_back(users[i].first.get_name());
		list[i].push_back(users[i].first.get_address());
		list[i].push_back(users[i].first.get_number());
		list[i].push_back(users[i].first.get_accType());
	}
	
		for(int i = 0 ; i < users.size() ; i++){
		list[i].push_back(users[i].second->get_ID());
		list[i].push_back(users[i].second->get_balance());
	}
	
	return list;
}

bool BankAppplication::withdraw(string accountID , double balance){
	for(int i = 0 ; i < users.size();i++){
		if(users[i].second->get_ID() == accountID){
			if(users[i].second->withdraw(balance)){
		set_data();
		return 1;
			}
		}
	}
	
	return 0;
}


bool BankAppplication::deposit(string accountID , double balance){
	for(int i = 0 ; i < users.size();i++){
		if(users[i].second->get_ID() == accountID){
		if(users[i].second->deposit(balance)){
		set_data();
		return 1;
		}
		}
	}
	
	return 0;
}


//BankAppplication::~BankAppplication(){
//	for(int i = 0 ; i < users.size() ; i++){
//		delete users[i].second;
//	}
//	
//}

string BankAppplication::get_ID(){
	return users[users.size()-1].second->get_ID();
}
