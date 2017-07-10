 //
// Domain Name System
// C++
//
// Created by Nino Leo on 2017/6/15.
// Copyright © Nino 2017. All rights reserved.
// 

#include "dns.h"
#include <utility>

using namespace std;

/*private:
    string _ip; 
    map< string, vector<string> > _map;
*/


dns::dns(string ip) : _ip(ip) {}
    

vector<string>& dns::operator[](const string& domain)  // return mutable ip_set
{
	std::vector<string> v;
	auto it = _map.find(domain);
	if(it == _map.end()) {
		_map.insert(std::pair< string, vector<string> >(domain,v));
		return _map.begin()->second;
	}
	else return it->second;
}

    /*
     *  if the domain maps at least one ip
     *  fot example, the dns server ip is 114.114.114.114
     *  the domain name is www.baidu.com
     *  and it maps 123.125.114.144, 220.181.57.217, 180.149.132.47
     *  then you should output like bellow
     *
     *  Server: 114.114.114.114
     *  Name: www.baidu.com
     *  Address: 123.125.114.144
     *  Name: www.baidu.com
     *  Address: 220.181.57.217
     *  Name: www.baidu.com
     *  Address: 180.149.132.47
     *
     *  if the domain doesn't map ip
     *  fot example, the dns server ip is 8.8.8.8
     *  the domain name is www.google.com, and doesn't map ip
     *  then you should output like bellow
     *
     *  Server: 8.8.8.8
     *  Server can't find www.google.com
     */
void dns::nslookup(const string& domain) {
	auto it = _map.find(domain);
	cout << "Server: " << _ip << endl;
	if(it == _map.end() || (it->second).size() == 0) {
		cout << "Server can't find " << domain << endl; 
		return ;
	}
	for(int i = 1; i < (it->second).size(); i++) {
		cout << "Name: " <<  domain << endl;
		cout << "Address: " << (it->second)[i] << endl;
	}
}
