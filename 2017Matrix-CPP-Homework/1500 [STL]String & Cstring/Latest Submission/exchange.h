#ifndef EXCHANGE_H_
#define EXCHANGE_H_

#include <string>
#include <sstream>

using namespace std;

std::string change1(const char* cstr) 
{ 
  std::string ret;
  stringstream ss;
  ss << cstr;
  ss >> ret;
  ss.clear();
  return ret;
}

void change2(std::string str, char* cstr) 
{ 
  stringstream ss;
  ss << str;
  ss >> cstr;
  ss.clear();
}

#endif