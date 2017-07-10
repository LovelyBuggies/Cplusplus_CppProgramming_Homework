//
// judge.h
// CPP
//
// Created by Nino Leo on 2017/06/09.
// Copyright © Nino 2017.06. All rights reserved.
//


#include <cstring>
#include <cstdlib>
#include <cctype>

// exception class
class NumberParseException
{
public:
    NumberParseException() {}
};


// judge whether is number
bool isNumber(const char *str) {
    if(!str) return false;
    if(strlen(str) == 0) return false;
    if(strlen(str) == 1 && !isdigit(str[0])) return false;
    for (int i = 0;i < strlen(str); ++i)
      if(!isdigit(str[i])){
        if(i == 0 && (str[i] == '+' || str[i] == '-')) 
          continue;
        else 
        	return false;
    }
    return true;
}


int parseNumber(const char *str)
{
    if (isNumber(str))
        return atoi(str);             // change a c_str to a number
    else 
        throw NumberParseException();
}