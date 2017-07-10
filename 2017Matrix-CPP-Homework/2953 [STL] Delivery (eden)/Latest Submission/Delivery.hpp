// 
// Delivery.hpp
// C++
// 
// Created by Nino Leo on 17/06/15.
// Copyright © Nino 2017. All rights reserved.
//

#ifndef DELIVERY_HPP
#define DELIVERY_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

std::vector<string> getInfoSort(std::vector<string> t_infos) {
	std::vector<string> ret;
	std::map<string, string> m_map;
    string date, condition;
    
    for(int i = 0; i < t_infos.size(); ++i) {
    	auto split = t_infos[i].find_first_of('|');
    	date = t_infos[i].substr(0, 19);
    	condition = t_infos[i].substr(split+1, 50);
    	auto it = m_map.find(condition);
    	if(it != m_map.end() && date < it->second)
    		m_map.erase(it);
    	m_map.insert ( std::pair<string, string>(condition, date) );
    }

    for(auto it = m_map.begin(); it != m_map.end(); it++) {
    	string str = "";
    	str = str + it->second;
    	str = str + " : ";
    	str= str + it->first;
    	ret.push_back(str);
    	str.clear();
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}

#endif
