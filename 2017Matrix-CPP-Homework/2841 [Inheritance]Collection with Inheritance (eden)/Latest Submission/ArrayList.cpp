//
// ArrayList.cpp
// C++
//
// Created by Nino Leo on 2017/06/03.
// Copyright © Nino 2017. All rights reserved.
//

#include "ArrayList.hpp"
#define MAX 1024

ArrayList::ArrayList() {
  _maxsize = MAX;
	storage = new E[_maxsize];
	_size = 0;
}
ArrayList::~ArrayList() {
	clear();
}
void ArrayList::add(E e) {
  if(_size+1 >= _maxsize)
    extend();
	storage[_size++] = e;
}
void ArrayList::clear(void) {
	delete []storage;
	_size = 0;
}
bool ArrayList::contain(E e) {
	for(int i = 0; i < _size; i++)
		if(storage[i] == e) 
			return true;
	return false;
}
bool ArrayList::isEmpty(void) {
	if(_size == 0) return true;
	return false;
}
void ArrayList::remove(E e) {
	while(contain(e)){
		for(int i = indexOf(e); i < _size-1; i++)
			storage[i] = storage[i+1];
		    _size--;
	}
}
E& ArrayList::operator[](int index) {
	return storage[index];
}
E& ArrayList::get(int index) {
	return storage[index];
}
int ArrayList::indexOf(E element) {
	for(int i = 0; i < _size; i++)
		if(element == storage[i])
			return i;
	return -1;
}
void ArrayList::sort(void) {
	for(int i = 0; i < _size; i++)
		for(int j = i+1; j < _size; j++)
			if(storage[j] < storage[i]) {
				E temp = storage[j];
				storage[j] = storage[i];
				storage[i] = temp;
			}
}
int ArrayList::size(void) {
	return _size;
}
void ArrayList::extend(void) {
  _maxsize *= extend_factor;
  E *temp = new E[_maxsize];
  for(int i = 0; i < _size; i++)
    temp[i] = storage[i];
  delete []storage;
  storage = temp;
}
