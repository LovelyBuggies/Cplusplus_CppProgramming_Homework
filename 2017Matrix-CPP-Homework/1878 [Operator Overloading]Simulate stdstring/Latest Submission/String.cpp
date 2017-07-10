//
// String.cpp
// C++
//
// Created by Nino on 2017.
// Copyright © Nino 2017. All rights reserved.
//

#include "String.h"
#include <cstring>
 
String::String() {
	_buff = NULL;
	_length = 0;
}
String::String(const char *other) {
	_length = strlen(other);
	_buff = new char[_length+1];
	for(int i = 0; i < _length; i++) {
		_buff[i] = other[i];
	}
}
String::String(const String &other) {
	_length = other._length;
	_buff = new char[_length+1];
	for(int i = 0; i < _length; i++) {
		_buff[i] = other._buff[i];
	}
}
String::~String() {clear();}

void String::assign(const char *other) {
	clear();
	_length = strlen(other);
	_buff = new char[_length+1];
	for(int i = 0; i < _length; i++) {
		_buff[i] = other[i];
	}
}

void String::append(const char &other) {
	char save[_length];
	for(int i = 0; i < _length; i++)
		save[i] = _buff[i];
	if(_buff)
	    delete [] _buff;
	_length++;
	_buff = new char[_length+1];
	for(int i = 0; i < _length-1; i++) {
		_buff[i] = save[i];
	}
	_buff[_length-1] = other;
}

void String::clear() {
	if(empty()) return;
	delete [] _buff;
	_buff = NULL;
	_length = 0;
}

int String::compare(const String &other) const{
    if(*this > other) return 1;
    else if(*this < other) return -1;
    return 0;
}

int String::length() const { return _length; }

const char* String::c_str() const { return _buff; }

bool String::empty() const { return (_length)? false : true;}



int String::find(const String &other, int pos) const {
    bool equal = true;
    while(pos < _length) {
    	if(_buff[pos] == other._buff[0]) {
    	    for(int i = 0; i < other._length; i++)
    	    	if(_buff[pos+i] != other._buff[i]) {
    	    		equal = false;
    	    		break;
    	    	}
    	    if(equal)
    	    	return pos;
    	    }
        pos += 1;
    }
    return _length;
}

String String::substr(const int &pos, const int &count) const {
	char save[count+1];
	memset(save,'\0',(count+1)*sizeof(char));
    for(int i = 0; i < count; i++)
    	if(pos+i < _length)
    	    save[i] = _buff[pos+i];
	return String(save);
}

char& String::operator[](const int &index) { return _buff[index]; }

void String::operator=(const String &other) {
	clear();
	_length = other.length();
	_buff = new char[_length+1];
	for(int i = 0; i < _length; i++) {
		_buff[i] = other._buff[i];
	}
}

void String::operator=(const char *src) {
	clear();
	_length = strlen(src);
	_buff = new char[_length+1];
	for(int i = 0; i < _length; i++) {
		_buff[i] = src[i];
 	}
}

String String::operator+(const String &other) const {
	String temp(*this);
	for(int i = 0; i < other._length; i++) {
		temp.append(other._buff[i]);
	}
	return temp;
}

bool String::operator<(const String &other) const {
	int sh = (_length > other.length())? other.length() : _length;
	for(int i = 0; i < sh; i++){
		if(_buff[i] > other._buff[i]) return false; 
		else if(_buff[i] < other._buff[i]) return true;
	}
	if(_length < other._length) return true;
    return false;
}

bool String::operator<=(const String &other) const {
    if(*this < other || *this == other) return true;
    return false;
}

bool String::operator>(const String &other) const {
	return (*this <= other)? false : true;
}

bool String::operator>=(const String &other) const {
	return (*this < other)? false : true;
}

bool String::operator==(const String &other) const {
	if(_length != other._length) return false;
	for(int i = 0; i<_length; i++) 
		if(_buff[i] != other._buff[i]) return false;
	return true;
}

bool String::operator!=(const String &other) const {
	return (*this == other)? false : true;
}

std::ostream& operator<<(std::ostream& out, const String &str){
	for(int i = 0; i < str.length(); i++)
		out << str.c_str()[i];
	return out;
}