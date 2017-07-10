//
// Factor. hpp
// C++
//
// Created by Nino on 2017/4/28.
// Copyright © Nino 2017. All rights reserved.
//

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Product.hpp"

class Factory {
public:
	Factory() {}
	virtual ~Factory() {}
	virtual Laptop* produceLaptop() = 0;
	virtual MobilePhone* produceMobilePhone() = 0;
};


class AppleFactory : public Factory {
public:
	AppleFactory() {}
	void Apple() {
		cout << "Apple ";
	}
	Laptop* produceLaptop() {
        return new Laptop(0);
	}
	MobilePhone* produceMobilePhone(){
		return new MobilePhone(0);
	}
};



class XiaomiFactory : public Factory {
public:
	XiaomiFactory() {}
	void Xiaomi() {
		cout << "Xiaomi ";
	}
	Laptop* produceLaptop() {
        return new Laptop(1);
	}
	MobilePhone* produceMobilePhone(){
		return new MobilePhone(1);
	}
};

#endif