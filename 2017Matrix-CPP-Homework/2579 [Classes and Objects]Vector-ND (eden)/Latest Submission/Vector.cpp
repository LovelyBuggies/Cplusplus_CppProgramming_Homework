 //
// Vector.h
// C++
// 
// Created by nino leo on 17/5/11.
// Copyright nino 2017. All rights reserved.
//

#include "Vector.h"
#include <iostream>
using namespace std;

// constructor, print out "construct a vector called vector_name.\n"

Vector::Vector(string s, int d, int p[]) {
	name = s;
	dimension = d;
	param = new int [d+1];
	for(int i = 0; i < d; i++)
		param[i] = p[i];
	cout << "construct a vector called " << name << ".\n";
}

// copy constructor, print out "copy a vector called vector_name.\n"

Vector::Vector(const Vector &otherVec) {
	name = otherVec.name;
	dimension = otherVec.dimension;
	param = new int [dimension+1];
	for(int i = 0; i < dimension; i++)
		param[i] = otherVec.param[i];
	cout << "copy a vector called " << name << ".\n";
} 
// destructor, print out "release memory from a vector called vector_name.\n"
Vector::~Vector() {
	delete [] param;
	param = NULL;
	cout << "release memory from a vector called " << name << ".\n";
}





void Vector::isEqual(const Vector &otherVec) {
	bool n = true;
	bool v = true;
	if(otherVec.name != name) 
		n = false;
	if(dimension != otherVec.dimension)
		v = false;
  else {
	for(int i = 0; i < dimension; i++) 
		if(param[i] != otherVec.param[i]) {
			v= false;
			break;
		}
  }
	if(n) {
		if(v)
		cout << "same name, same value.\n";
	    else
	 	cout << "same name, different value.\n";
	}
	else {
		if(v)
        cout << "different name, same value.\n";
        else
		cout << "different name, different value.\n";
	}
}

void Vector::setName(string n) {
    name = n;
}

// display the vecter in the format "vecter_name(1, 2..N)\n"      

void Vector::print() {
	cout << name << "(";
	for(int i = 0; i < dimension-1; i++) {
		cout << param[i] << ", ";
	}
	cout << param[dimension-1] << ")" << endl;
}
