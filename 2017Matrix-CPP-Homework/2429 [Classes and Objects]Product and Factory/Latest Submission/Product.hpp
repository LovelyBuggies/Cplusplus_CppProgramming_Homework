//
// Product. hpp
// C++
//
// Created by Nino on 2017/4/28.
// Copyright © Nino 2017. All rights reserved.
//

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

using namespace std;



class Laptop {
private:
	int interface;
public:
	Laptop() {}
	Laptop(int m) : interface(m) {}
	void compileCppProgram() {
        if(interface == 0)
		    cout << "Apple Laptop compiles a cpp program." << endl;
        else
            cout << "Xiaomi Laptop compiles a cpp program." << endl;
    }
};



class MobilePhone {
private:
	int interface;
public:
	MobilePhone(){}
	MobilePhone(int m) : interface(m) {}
	void sendShortMessage() {
        if(interface == 0)
		    cout << "Apple MobilePhone sends a short message." << endl;
        else
            cout << "Xiaomi MobilePhone sends a short message." << endl;
    }
};

#endif