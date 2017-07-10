//
// LinkedList.cpp
// C++
//
// Created by Nino Leo on 2017/06/03.
// Copyright © Nino 2017. All rights reserved.
//

#include "LinkedList.hpp"
  
LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	_size = 0;
}
LinkedList::~LinkedList() {
	clear();
}
void LinkedList::add(E e) {
	if(this->isEmpty()) {
		head = tail = new node(e);
		_size++;
		return ;
	}
	tail->next = new node(e);
	node *temp = tail;
	tail = temp->next;
	tail->prev = temp;
	_size++;
}
void LinkedList::clear(void) {
	if(this->isEmpty()) return;
	node *p = head;
	node *q = head;
	while(p) {
		q = p->next;
		delete p;
		p = q;
	}
	head = tail = NULL;
  _size = 0;
}
bool LinkedList::contain(E e) {
	node *p = head;
	while(p) {
		if(p->data == e)
			return true;
		p = p->next;
	    }
	return false;
}
bool LinkedList::isEmpty(void) {
	if(_size == 0) return true;
	return false;
}
void LinkedList::remove(E e) {
  if(_size == 0) return;
	while(contain(e)){
	if(_size == 1 && e == head->data) {
		delete head;
    head = tail = NULL;
    _size = 0;
		return;
	}
	if(e == head->data) {
		node *p = head->next;
		delete head;
		head = p;
		_size--;
		continue;
	}
	if(e == tail->data) {
		node *p = tail->prev;
		delete tail;
		tail = p;
		_size--;
		continue;
	}
	node *p = head;
	while(p) {
    node *q = p->next;
		if(p->data == e) {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			p = NULL;
			_size--;
			}
			p = q;
		}
	}
}
E& LinkedList::operator[](int index) {
	node *p = head;
	for(int i = 0; i < index; i++)
		p = p->next;
	return p->data;
}
E& LinkedList::get(int index) {
	node *p = head;
	for(int i = 0; i < index; i++)
		p = p->next;
	return p->data;
}
int LinkedList::indexOf(E element) {
	node *p = head;
	int index = 0;
	while(p) {
		if(p->data == element)
			return index;
		p = p->next;
		index++;
	}
    return -1;
}

void swap(LinkedList::node *a, LinkedList::node *b) {
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}

LinkedList::node* getSeperator(LinkedList::node *Pbegin, LinkedList::node *Pend) {
  LinkedList::node *p = Pbegin;
  LinkedList::node *q = Pbegin->next;
  int key = p->data;
  while(q) {
    if(q->data < key){
      p = p->next;
      swap(p,q);
    }
    q = q->next;
  }
  swap(Pbegin, p);
  return p;
}

void Qsort(LinkedList::node *Pbegin, LinkedList::node *Pend) {
  if(Pbegin != Pend) {
    LinkedList::node *seperator = getSeperator(Pbegin, Pend);
    Qsort(Pbegin, seperator);
    Qsort(seperator->next, Pend);
  }
}

void LinkedList::sort(void) {
  if(_size <= 1) return ;
  Qsort(head, tail);
}
int LinkedList::size(void) {
	return _size;
}

