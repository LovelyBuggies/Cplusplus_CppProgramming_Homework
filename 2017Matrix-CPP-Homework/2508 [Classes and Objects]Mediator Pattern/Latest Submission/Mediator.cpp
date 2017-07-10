// 
// Mediator.cpp
// C++
//
// Created by Nino on 2017/5/7.
// Copyright © Nino 2017. All rights reserved.
//

#include "Mediator.hpp"

Mediator* Mediator::Ins = NULL;
void Mediator::RegisterHandler(User * u){
	std::list<User*>::iterator itr;
	for(itr = users.begin(); itr != users.end(); itr++)
		if((*itr)->getId() == u->getId()) 
			break;
	if(itr == users.end())
		this->users.push_back(u);
}



void Mediator::ChatHandler(const int & to, const string & msg){
	if(to == -1) return;
    std::list<User*>::iterator itr;
	for(itr = users.begin(); itr != users.end(); itr++)
		if((*itr)->getId() == to) {
			(*itr)->GetMessage(msg);
			break;
		}
	if(itr == users.end())
		cout << "There is no such a guy!" << endl;
}



void Mediator::DressInfoHandler(const int & to) {
  std::list<User*>::iterator itr;
	for(itr = users.begin(); itr != users.end(); itr++)
		if((*itr)->getId() == to) {
			(*itr)->ShowMyCuteDresses();
			break;
		}
	if(itr == users.end())
		cout << "There is no such a guy!" << endl;
}



pair<int,string> Mediator::TradeHandler(const int & to, const int & pay, const string & dressName) {
    std::list<User*>::iterator itr;
	for(itr = users.begin(); itr != users.end(); itr++)
		if((*itr)->getId() == to)
			return (*itr)->SellBeautifulDress(pay, dressName);
	if(itr == users.end())
		cout << "There is no such a guy!" << endl;
	return std::make_pair(-1,"");
}
