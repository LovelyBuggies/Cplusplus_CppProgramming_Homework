#include "Account.h"
#include <cstdio>

//static initial
int Account::_total_account=0;

//con/de structor
Account::Account(){
    _id=_balance=0;
    _valid=0;
    _total_account++;
}
Account::~Account(){
    _total_account--;
}

//returns
int Account::id() const{
    return _id;
}
int Account::get_total_account(){
    return _total_account;
}
double Account::balance() const{
    return _balance;
}
bool Account::valid() const{
    return _valid;
}

std::string Account::profile() const{
    char str[1024];
    std::string s;
    sprintf(str,"ID:%d\nBALANCE:%.6lf\nVALID:N\n",_id,_balance);
    s=str;
    return s;
}
void Account::reset(){
    _balance=0;
    _valid=0;
}

//money alteration
bool Account::deposit(const double &num){
    if(num<0) return false;
    _balance+=num;
    return true;
}
bool Account::draw(const double &num){
    if(_balance-num<=0.01) return false;
    _balance-=num;
    return true;
}

