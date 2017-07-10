
#include "test.hpp"
#include "user.hpp"
#include <cctype>

using namespace alipay;
using namespace std;

inline bool alipay::User::verifyPasswordFormat(const std::string &pass)
{
  if(pass.length() > 20 || pass.length() < 8) 
    return false;
  for (int i=0;i<pass.length();i++)
    if (isalpha(pass[i]) == 0 && isdigit(pass[i]) == 0)
     return false;
  return true;
}

inline bool alipay::User::verifyUsernameFormat(const std::string &un)
{
  if(un.length() > 20 || un.length() < 6) 
    return false;
  for (int i=0;i<un.length();i++)
    if (isalpha(un[i]) == 0 && isdigit(un[i]) == 0)
     return false;
  return true;
}

inline bool alipay::User::verifyPhoneFormat(const std::string &ph)
{
  if (ph.length() != 13) 
    return false;
  for (int i=0;i<ph.length();i++)
     if(( ph[i]>'9' )||( ph[i]<'0' ))
     return false;
  return true;
}



bool alipay::User::setUsername(const char *name)
{
  username = name;
  return verifyUsernameFormat(username);
}

bool alipay::User::setPassword(const char *new_password, const char *old_password)
{
  password = new_password;
  return verifyPasswordFormat(password);
}
bool alipay::User::setPhone(const char *new_phone)
{
  bool r;
  phone=new_phone;
  r=verifyPhoneFormat(phone);
  return r;
}
bool alipay::User::setGender(Gender::Gender gend)
{
  bool r;
  r=false;
  if ((gend==0)||(gend==1)) r=true;
  gender=gend;
  return r;
}




std::string alipay::User::getUsername(void)
{
  return username;
}
std::string alipay::User::getPhone(void)
{
  return phone;
}
alipay::Gender::Gender alipay::User::getGender(void)
{
  return gender;
}
  
  // if passowrd is in correct, return -1
long long int alipay::User::getMoneyAmount(const char *pass)
{
  if (pass == password)
     return balance;
  else 
    return -1;
}
bool alipay::User::deposit(long long int amount)
{
  bool r;
  if (amount <0) r=false;
  else
   {
   balance=balance+amount;
   r=true;    
   }
  return r;
}
bool alipay::User::withdraw(long long int amount, const char *pw)
{
  bool r;
  if (getMoneyAmount(pw)==-1)
     r=false;
  else if (amount<0) r=false;
  else 
   {
     balance=getMoneyAmount(pw)-amount;
       if (balance<0) r=false;
       else
       r=true;
   }
  return r;
}