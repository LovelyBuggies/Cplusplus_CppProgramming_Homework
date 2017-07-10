
// ***************************************************************
// main.cpp
// function: using associative container to save QQ IP.
//           users can use this project to search for a QQ's IP.
//           usets can also use it to search for a IP's QQ number.
// method: creat two maps -- map1<ip, qqset> , map2<qq, ipset>.
//         for map1 -- add qq to qqset with particular ip,
//         fpr map2 -- add ip to ipset with special qq.
//         judge whether the set is empty
//****************************************************************

#include <iostream>
#include <map>
#include <set>
#include <iterator>
#include <string>

using namespace std;

int main() {
    map<string, set<string> > ip_qq;
    map<string, set<string> > qq_ip;
    int n;
    cin >> n;
  	string qq, ip;
    for (int i = 0; i < n; i++) {
      cin >> qq >> ip;
      ip_qq[ip].insert(qq);
      qq_ip[qq].insert(ip);
    }
  
    cin >> ip;
    if (ip_qq.find(ip) == ip_qq.end()) {
        cout << "no qq" << endl;
    } 
    else {
        cout << ip << " ==> [ ";
        for (auto it = ip_qq[ip].begin(); it != ip_qq[ip].end(); it++) {
            cout << *it << " ";
        }
        cout << "]" << endl;
    }

    cin >> qq;
    if (qq_ip[qq].empty()) {
        cout << "no ip" << endl;
    } 
    else {
        cout << qq << " ==> [ ";
        for (auto it = qq_ip[qq].begin(); it != qq_ip[qq].end(); it++) {
            cout << *it << " ";
        }
        cout << "]" << endl;
    }
}
