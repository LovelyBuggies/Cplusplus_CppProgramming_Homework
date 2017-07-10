#include "PersonalAccount.h"
#include <cstdio>

//static initial
int PersonalAccount::_total_per_account=0;
int PersonalAccount::_acc_id_ptr=12010000;

//con/de structor
PersonalAccount::PersonalAccount() : Account() {
	_total_per_account++;
    _id=_acc_id_ptr;
    _acc_id_ptr++;
	_balance=10;
	_valid=1;

}
PersonalAccount::~PersonalAccount() {
	_total_per_account--;
}

// override
std::string PersonalAccount::profile() const{
    char str[1024];
    std::string s;
    sprintf(str,"ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:PERSONAL\n",_id,_balance);
    s=str;
    return s;
}
void PersonalAccount::reset(){
	_balance=10;
	_valid=1;
}

// static return
int PersonalAccount::get_total_per_account(){
	return _total_per_account;
}