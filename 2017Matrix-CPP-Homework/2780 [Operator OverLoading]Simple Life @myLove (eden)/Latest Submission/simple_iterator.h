
//
// simple_simple_iterator.h
// CPP
// Created by Nino Leo on 2017.
// Copyright © Nino 2017. All rights reserved.
//

class simple_iterator
{
public:
  simple_iterator() {}
  simple_iterator(char* x) :p(x) {}
  simple_iterator(const simple_iterator& mit) : p(mit.p) {}
  simple_iterator begin() {
  	simple_iterator temp(*this);
  	while(*(temp-1) != '\0')
  		temp--;
  	return temp;
  }
  simple_iterator end() {
  	simple_iterator temp(*this);
  	while(*(temp+1) != '\0')
  		temp++;
  	return temp;
  }
  simple_iterator prev() {
  	simple_iterator temp(*this);
  	return (temp-1);
  }
  simple_iterator next() {
  	simple_iterator temp(*this);
  	return (temp+1);
  }
  simple_iterator& operator=(const simple_iterator& mit) {
  	p = mit.p;
  	return *this;
  }
  simple_iterator& operator++() {
  	++p;
  	return *this;
  }
  simple_iterator operator++(int) {
  	simple_iterator tmp(*this); 
  	operator++(); 
  	return tmp;
  }
  simple_iterator& operator--() {
  	--p;
  	return *this;
  }
  simple_iterator operator--(int) {
  	simple_iterator tmp(*this); 
  	operator--(); 
  	return tmp;
  }
  bool operator==(const simple_iterator& rhs) const {
  	return p==rhs.p;
  }
  bool operator!=(const simple_iterator& rhs) const {
  	return p!=rhs.p;
  }
  char& operator*() {
  	return *p;
  }
  bool operator<(const simple_iterator& rhs) const {
  	return ((*p - *rhs.p) < 0)? true : false;
  }
  bool operator<=(const simple_iterator& rhs) const {
  	return ((*p - *rhs.p) <= 0)? true : false;
  }
   bool operator>(const simple_iterator& rhs) const {
  	return ((*p - *rhs.p) > 0)? true : false;
  }
  bool operator>=(const simple_iterator& rhs) const {
  	return ((*p - *rhs.p) >= 0)? true : false;
  }
  simple_iterator operator+(int x) const {
  	simple_iterator temp(*this);
  	temp.p += x;
  	return temp;
  }
  simple_iterator operator-(int x) const {
  	simple_iterator temp(*this);
  	temp.p -= x;
  	return temp;
  }
private:
	char* p;
};