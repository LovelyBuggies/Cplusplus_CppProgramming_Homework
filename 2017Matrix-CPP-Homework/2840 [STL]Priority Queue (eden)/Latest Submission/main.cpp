//
// main.cpp
// C++
//
// caculate the time to print your job
//
// Created by Nino Leo on 2017/06/01.
// Copyright © Nino 2017. All rights reserved.

#include <iostream>
#include <deque>

using namespace std;

int main() {
	int times;
	cin >> times;
	while(times--) {
		std::deque<int> q;
	    std::deque<int>::iterator it;
		bool ok = false;
		int min = 0;
		int num, mpos;
		cin >> num >> mpos;
		for(int i = 0; i < num; i++) {
			int pri;
			cin >> pri;
            q.push_back(pri);
		}
		while(!ok){
			for(int i = 0; i < mpos; i++) {
				int t = q.front();
				q.pop_front();
				min++;
				for(it = q.begin(); it != q.end(); it++)
					if(*it > t){
						q.push_back(t);
						min--;
						break;
					}
			}
			ok = true;
			int m = q.front();
			q.pop_front();
			min++;
			for(it = q.begin(); it != q.end(); it++)
				if(*it > m){
					ok = false;
					q.push_back(m);
					min--;
					break;
				}
			if(!ok) mpos = q.size()-1;
		}
		cout << min << endl;
	}
	return 0;
}