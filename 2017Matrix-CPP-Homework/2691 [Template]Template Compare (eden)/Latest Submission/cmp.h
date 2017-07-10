// 
// cmp.h
// C++
// 
// Created by Nino on 2017/5/18.
// Copyright © Nino 2017. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
bool cmp(const T& a, const T& b) {
   if(a == b) return true;
   return false;
}


bool cmp(char* a, char* b) {
 if(strlen(a) != strlen(b))
   return false;
if(strcmp(a, b) == 0) return true;
  return false;
}


template <typename T>
bool cmp(T* a, T* b) {
   if(*a == *b) return true;
   return false;
}