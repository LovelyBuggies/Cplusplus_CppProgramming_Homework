#include "VIPAccount.h"
#include <cstdio>

//static initial
int VIPAccount::_total_vip_account=0;
int VIPAccount::_acc_id_ptr=12050000;

VIPAccount::VIPAccount() : Account() {
	_id=_acc_id_ptr;
	_acc_id_ptr++;
    _total_vip_account++;
	_balance=10;
	_valid=1;
	_loan_limit=1e3;
	_loan=0;
}
VIPAccount::~VIPAccount() {
	_total_vip_account--;
	_loan_limit=0;
	_loan=0;
}

//loan 
bool VIPAccount::loan(const double &num) {
	if(_loan+num>_loan_limit||num<0) return false;
	_valid=1;
	_loan+=num;
	_balance+=num;
	return true;
}
bool VIPAccount::repay(const double &num) {
	if(num>_balance||num>_loan) return false;
	_loan-=num;
	_balance-=num;
	return true;
}

// override
std::string VIPAccount::profile() const {
    char str[1024];
    std::string s;
    sprintf(str,"ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:VIP\nLOAN:%.6lf,LIMIT:%.6lf\n",_id,_balance,_loan,_loan_limit);
    s=str;
    return s;
}
void VIPAccount::reset() {
	_balance=10;
  _loan=0;
	_valid=1;
}

// static
int VIPAccount::get_total_vip_account() {
	return _total_vip_account;
}