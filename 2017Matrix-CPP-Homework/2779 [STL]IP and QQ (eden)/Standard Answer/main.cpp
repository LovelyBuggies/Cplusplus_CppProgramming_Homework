#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
  map<string, set<string> > ip2qq;
  map<string, set<string> > qq2ip;

  int n;
  string qq, ip;
  cin >> n;
  while (n--) {
    cin >> qq >> ip;
    ip2qq[ip].insert(qq);
    qq2ip[qq].insert(ip);
  }

  map<string, set<string> >::iterator it;
  set<string>::iterator its;
  cin >> ip;
  if (ip2qq.find(ip) == ip2qq.end()) {
    cout << "no qq" << endl;
  } else {
    cout << ip <<  " ==> [ ";
    for (its = ip2qq[ip].begin(); \
         its != ip2qq[ip].end(); its++) {
      cout << *its << " ";
    }
    cout << "]" << endl;
  }

  cin >> qq;
  if (qq2ip.find(qq) == qq2ip.end()) {
    cout << "no ip" << endl;
  } else {
    cout << qq <<  " ==> [ ";
    for (its = qq2ip[qq].begin(); \
         its != qq2ip[qq].end(); its++) {
      cout << *its << " ";
    }
    cout << "]" << endl;
  }

  return 0;
}
