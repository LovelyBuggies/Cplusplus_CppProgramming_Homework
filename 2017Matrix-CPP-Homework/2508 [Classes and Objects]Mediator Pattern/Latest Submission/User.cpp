//
// User.cpp
// C++
//
// Created by Nino on 2017/5/7.
// Copyright © Nino 2017. All rights reserved.
//

#include "User.hpp"
#include "Mediator.hpp"
#include <iterator>


int User::Count = 0;
User::User(const string & name, const int & money, 
	const vector<pair<string, int> > & dresses) {
	this->id = Count++;
	this->name = name;
	this->money = money;
	for(int i = 0; i < dresses.size(); i++) {
		Dress temp(dresses[i].first, dresses[i].second);
		this->dresses.push_back(temp);
	}
}



// handle chattings
void User::SendMessage(const int & to, const string & msg) {
	Mediator::getInstance()->ChatHandler(to, msg);
}
void User::GetMessage(const string & msg) {
	cout << this->name <<" : I got a Msg - " << msg << endl;
}



// handle dressinfos
void User::GetDressInfo(const int & id) {
    cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
    Mediator::getInstance()->DressInfoHandler(id);
}
void User::ShowMyCuteDresses() {
	cout << this->name << " : ok,these are all I have : "<<endl;
    for(int i = 0; i < dresses.size(); i++)
        cout << dresses[i].getName() << "-" << dresses[i].getPrice() << endl;
}



// handle trades
void User::BuyBeautifulDress(const int & id, 
	const int & pay, const string & name) {
	if(pay > money) {
		cout << this->name << " : " << "Forget to Check Wallet!" << endl;
		return ;
	}
	pair<int, string> p;
	p = Mediator::getInstance()->TradeHandler(id, pay, name);
  int left = p.first;
  string suit = p.second;
  
  if(suit == "no such suit")
	    cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
  else if(left == pay)
      cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;
  else if(left < pay) {
      cout << this->name << " : " << "So happy to get new Dress!" << endl;
      money = money - (pay - left);
      dresses.push_back(Dress(suit, pay - left));
      }
}
pair<int, string> User::SellBeautifulDress(const int & pay, const string & dname) {
  for(int i = 0; i < this->dresses.size(); i++)
		if(this->dresses[i].getName() == dname) {
			if(pay < dresses[i].getPrice()) {
				cout << this->name << " : " <<  "No monry then no talking" << endl;
				return std::make_pair(pay, dname);
			}
			else {
				cout << this->name << " : " << "What a good taste you have !" << endl;
				dresses.erase(dresses.begin()+i);
				money += dresses[i].getPrice();
				return std::make_pair(pay - dresses[i].getPrice(), dname);
			}
		}
	cout << this->name <<" : " << "I never have this Dress stupid!" << endl;
	return std::make_pair(pay, "no such suit");
}
