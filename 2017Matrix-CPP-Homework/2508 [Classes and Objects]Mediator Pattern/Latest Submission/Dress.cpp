 // 
// Dress.cpp
// C++
//
// Created by Nino on 2017/5/7.
// Copyright © Nino 2017. All rights reserved.
//

#include "Dress.hpp"

Dress::Dress(const string & name, const int price) {
	this->name = name;
	this->price = price;
}
Dress::Dress(const Dress & oth) {
	this->name = oth.getName();
	this->price = oth.getPrice();
}



int Dress::getPrice() const {
	return price;
}
string Dress::getName() const {
	return name;
}