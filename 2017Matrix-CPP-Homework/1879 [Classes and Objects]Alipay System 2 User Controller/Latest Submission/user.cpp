//
// user.cpp
// C++
//
// Created by Nino on 17/4/23.
// Copyright ©Nino 2017. All rights reserved.
//

#include "user.hpp"
#include <cstring>



Alipay::user::user(const char* username, const char* password) {
	this->setUsername(username);
	this->setPassword(password);
	balance = 0;
}
Alipay::user::~user() {}



const char* Alipay::user::getUsername() const {
    return username;
}
const char* Alipay::user::getPassword() const {
    return password;
}
double Alipay::user::getBalance() {
  	return balance;
}  



const void Alipay::user::setUsername(const char* username) {
	strcpy(this->username, username);
}
const void Alipay::user::setPassword(const char* password) {
  	strcpy(this->password, password);
}


 
bool Alipay::user::withdraw(double amount) {
  	if(amount < 0 || balance-amount < 0) return false;
  	balance -= amount;
  	return true;
}
bool Alipay::user::deposite(double amount) {
  	if(amount < 0) return false;
  	balance += amount;
  	return true;
}



//
// properties
//
// char username[21];
// char password[21];
// double balance;
//