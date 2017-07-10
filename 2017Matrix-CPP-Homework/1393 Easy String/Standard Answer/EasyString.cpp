#include "EasyString.hpp"
void Assign(char * & str, int length) {
  str = new char[length+1];
  return;
}

void AddTwo(string & res, char * & str1, char * & str2) {
  res = str1;
  res += str2;
  delete []str1;
  delete []str2;
  str1 = str2 = NULL;
  return;
}