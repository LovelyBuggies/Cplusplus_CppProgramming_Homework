//
// userController.cpp
// C++
//
// Created by Nino on 17/4/23.
// Copyright ©Nino 2017. All rights reserved.
//

#include "userController.hpp"
#include <cctype>
#include <string>
#include <cstring>



Alipay::userController::userController(double interest_rate) : interest_rate(interest_rate) {
	usercount = 0;
}
// clear userController
Alipay::userController::~userController() {
  	for(int i = 0; i < usercount; i++) {
  		delete users[i];
  	}
}



// vertify in the userController
bool Alipay::userController::createUser(const char* username, const char* password) {
	if(strlen(password) < 8 || strlen(password) > 20) return false;
	for(int i = 0; i < strlen(password); i++)
	{
		if(isalpha(password[i]) == 0 && isdigit(password[i]) == 0) return false;
	}
	if(strlen(username) < 6 || strlen(username) > 20) return false;
	for(int i = 0; i < strlen(username); i++)
	{
		if(isalpha(username[i]) == 0 && isdigit(username[i]) == 0) return false;
	}
	users[usercount++] = new user(username, password);
	return true;
}
// need not swap last and index
// only to change the cell pointers point
bool Alipay::userController::removeUserByUsername(const char* username) {
  	int index = getUserIndex(username);
  	if(index == -1) return false;
  	delete users[index];
    for(int i = index; i < usercount; i++)
    	users[i] = users[i+1];
    usercount--;
  	return true;
}



// justify whether container has in usercontroller
// justify whether amount is valid in user
bool Alipay::userController::deposite(const char* username, double amount) {
	int index = getUserIndex(username);
	if(index == -1) return false;
    return users[index]->deposite(amount);
}
bool Alipay::userController::withdraw(const char* username, double amount) {
	int index = getUserIndex(username);
	if(index == -1) return false;
	return users[index]->withdraw(amount);
}



int Alipay::userController::getUserIndex(const char* username) const {
  	for(int i = 0; i < usercount; i++) {
        if(strcmp(users[i]->getUsername(), username) == 0) 
        	return i;
  	}
  	return -1;
}
// sprintf need not a headfile
// also can change a format to the char*
std::string Alipay::userController::getUserInfoByName(const char* username_) const {
	int index = getUserIndex(username_);
	if(index == -1) return "";
	// pay attention to the 100
	// it will be fail to use a smaller size
    char temp[100];
    sprintf(temp,"username:%s\npassword:*********\nbalance:%g",username_,users[index]->getBalance());
    // force change type
    return (std::string)temp;
}  
int Alipay::userController::getUserCount(void) const{
  	return usercount;
}


  
bool Alipay::userController::setInterest(double interest) {
  	if(interest <= 0) return false;
    interest_rate = interest;
    return true;
}
void Alipay::userController::payInterest(void) {
    for(int i = 0; i < usercount; i++){
        double amount = users[i]->getBalance() * interest_rate;
        this->deposite(users[i]->getUsername(),amount);
    }    
}



//
// properties
//
// double interest_rate;
// user* users[MAX_USER];
// int usercount;