//
// Biginteger.cpp
// Created by Nino on 2017/07/06.
// Copyright Nino 2017. All rights reserved.
//

#include "Biginteger.h"
#include <cstring>

using namespace std;

BigInteger::BigInteger() {
	size_ = 0;
	data_ = NULL;
}

BigInteger::BigInteger(const string& number) {
	size_ = number.length();
	data_ = new int[size_+1];
	memset(data_, 0, (size_+1) * sizeof(int));
	for(int i = 0; i < this->size_; i++)
	// reverse for carriment of add
		data_[i] = number[size_-1-i] - '0';
}
BigInteger::BigInteger(const BigInteger& other) {
    size_ = other.size_;
    data_ = new int[size_+1];
    memset(data_, 0, (size_+1) * sizeof(int));
    for(int i = 0; i < size_; ++i)
    	data_[i] = other.data_[i];
}

BigInteger::~BigInteger() { delete [] data_; }

BigInteger operator+(const BigInteger& left, const BigInteger& right) {
    BigInteger temp = left.size_ > right.size_? left : right;
    BigInteger adder = left.size_ > right.size_? right : left;
    for(int i = 0; i < adder.size_; ++i) 
    	temp.data_[i] += adder.data_[i];
  	for(int i = 0; i < temp.size_; ++i)
    	if(temp.data_[i] > 9) {
    		temp.data_[i] %= 10;
    		temp.data_[i + 1]++;
    	}
    return temp;
}

// promise left >= right
BigInteger operator-(const BigInteger& left, const BigInteger& right) {
	BigInteger temp(left);
	for(int i = 0; i < right.size_; i++)
		temp.data_[i] = left.data_[i] - right.data_[i];
	for(int i = 0; i < temp.size_; i++)
		if(temp.data_[i] < 0) {
			temp.data_[i] += 10;
			temp.data_[i+1]--;
		}
	if(!temp.data_[temp.size_-1]) temp.size_--;
	return temp;
}

ostream& operator<<(ostream& out, const BigInteger& Bint) {
	for(int i = Bint.size_-1; i >= 0; i--) 
		out << Bint.data_[i];
	return out;
}