#include <string>
#include "EasyString.hpp"

using namespace std;

void Assign(char * &str, int l)
{
  str = new char [l + 1];
}

void AddTwo(string &s, char * &t_str, char * &t_string)
{
  std::string s1 = t_str;
  std::string s2 = t_string;
  s = s1 + s2;
  delete [] t_str;
  delete [] t_string;
  t_str = t_string = 0;
}

