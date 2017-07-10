//
//Set.cpp
//C++
//
//Created by Nino on 2017/4/18.
//Copyright © 2017 Leo. All rights reserved.
//

#include "Set.hpp"

Set::Set(){ size=0; }
    
Set::Set(int* m, int s) : size(s){
    for(int i = 0;i < size; i++)
    	members[i]=m[i];
}

Set::Set(Set const &s){
	this->size = s.size;
	for(int i=0;i<size;i++)
    members[i]=s.members[i];
}
    
bool Set::append(int e){
	if(this->isInSet(e)) 
    return false;
	members[size++] = e;
	return true;
}
    
bool Set::remove(int e){
  for(int i = 0; i < size; i++)
    if(members[i] == e) {
      members[i] = members[size - 1];
      size--;
      return true;
    }
  return false;
}
    
bool Set::isEmptySet(){
	return (size==0)? true : false;
}
    
bool Set::isInSet(int e){
	for(int i = 0;i < size; i++)
    if(members[i] == e) 
      return true;
	return false;
}
    
Set Set::operator&(const Set &s){
	Set temp;
	for(int i=0;i<s.size;i++)
		if(isInSet(s.members[i])) 
      temp.append(s.members[i]);
  return temp;
}

Set Set::operator|(const Set &s){
	Set temp(*this);
	for(int i = 0; i < s.size; i++)
		temp.append(s.members[i]);
	return temp;
}

Set Set::operator-(const Set &s){
	Set temp(*this);
	for(int i = 0; i < s.size; i++)
		temp.remove(s.members[i]);
	return temp;
}

Set Set::operator+(const Set &s){
	Set temp(s);
	return (*this - temp) | ( temp - *this);
}

int* Set::getMembers(){ return members;}

int Set::getSize(){ return size; }