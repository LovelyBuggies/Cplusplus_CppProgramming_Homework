#include "MyInteger.hpp"
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>

MyInteger::MyInteger(int nnnn):value(nnnn){}

int MyInteger::getValue() const
{
  return value;
}

bool MyInteger::isEven() const
{
  bool rrrr;
  if (value%2==0)
  rrrr=1;
  else
  rrrr=0;
  return rrrr;
}

bool MyInteger::isOdd() const
{
  bool rrrr;
  if (value%2==0)
  rrrr=0;
  else
  rrrr=1;
  return rrrr;
}
    
bool MyInteger::isPrime() const
{
  bool prime=1;
  int div;
  if (value==2) prime=1;
  else if (value==1) prime=0;
  else
   {
  for (div=2;div<=sqrt(value);div++)
     if (value%div==0)
     {
      prime=0;break;
      }
    }
  return prime;
}

bool MyInteger::isEven(int nnnn)
{
  bool even;
  if (nnnn%2==0) even=1;
  else even=0;
  return even;
}

bool MyInteger::isOdd(int nnnn)
{
  if (nnnn%2) return true;
  return false;
}

bool MyInteger::isPrime(int nnnn)
{
  bool prime=1;
  int div;
  if(nnnn==2) prime=1;
  else if (nnnn==1) prime=0;
  else
   {
  for (div=2;div<=sqrt(nnnn);div++)
     if (nnnn%div==0)
     {
      prime=0;break;
      }
    }
  return prime;
}

bool MyInteger::isEven(const MyInteger& reference)
{
  bool even;
  if (reference.value%2==0) even=1;
  else even=0;
  return even;
}

bool MyInteger::isOdd(const MyInteger&reference)
{
  if (reference.value%2) return true;
  return false;
}

bool MyInteger::isPrime(const MyInteger&rrrr)
{
  bool prime=1;
  int div;
  if(rrrr.value==2) prime=1;
  else if (rrrr.value==1) prime=0;
  else
  {
  for (div=2;div<=sqrt(rrrr.value);div++)
     if (rrrr.value%div==0)
     {
      prime=0;break;
      }
   }
   return prime;
}

bool MyInteger::equals(int nnnn)
{
  bool rrrr;
  if (nnnn==this->value) rrrr=1;
  else rrrr=0;
  return rrrr;
}

bool MyInteger::equals(const MyInteger&reference )
{
  bool rrrr;
  if (value==(reference.value))
     rrrr=1;
  else rrrr=0;
  return rrrr;
}

int MyInteger::parseInt(const std::string&tttt)
{
  int nnnn,llll,ssss=0;
  llll=tttt.length();
  
  if (isdigit(tttt[0]))
  {
   for(int i=0;i<llll;i++)
   {nnnn=tttt[i]-'0';ssss=ssss+nnnn*pow(10,llll-i-1);}
  }
  
  else
   {
   llll-=1;
   for(int i=1;i<=llll;i++)
   { nnnn=tttt[i]-'0'; ssss=ssss+nnnn*pow(10,llll-i);}
   ssss=-ssss;
   }
  return ssss;
}