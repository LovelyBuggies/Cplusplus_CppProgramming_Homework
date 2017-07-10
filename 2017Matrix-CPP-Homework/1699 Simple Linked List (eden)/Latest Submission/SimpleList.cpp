//
//SimpleList.hpp
//C++
//Created by Nino on 17/04/22
//Copyright © Nino 2017. All rights reserved.
//

#include "SimpleList.hpp"
#include <cstdio>

list::list() {
	head = 0;
	_size = 0;
}
list::list(const list& temp) {
	if(temp.head == NULL) return;
	head = new node(temp.head->data, NULL);
	node *p = temp.head->next;
	node *q = this->head;
	while(p != NULL) {
		q->next = new node(p->data, NULL);
		q = q->next;
		p = p->next;
	}
	this->_size = temp._size;
}

list& list::operator=(const list &temp) {
	if(&temp == this) return *this;
	this->clear();
	if(temp.head == NULL) return *this;
	head = new node(temp.head->data, NULL);
	node *p = temp.head->next;
	node *q = this->head;
	while(p != NULL) {
		q->next = new node(p->data, NULL);
		q = q->next;
		p = p->next;
	}
	this->_size = temp._size;
	return *this;
}
list::~list() {
	clear();
}
 
// Capacity
bool list::empty(void) const {
	return (_size == 0) ? 1 : 0;
}
int list::size(void) const {
	return _size;
}

// output
// list: [1,2,3,4,5]
// output: 1->2->3->4->5->NULL
std::string list::toString(void) const {
    if(this->empty()) return "NULL";
    std::string s;
    node *p = head;
    while(p != NULL){
    	char c[10];
    	sprintf(c, "%d" ,p->data);
    	s = s+c+"->";
    	p = p->next;
    }
    s = s+"NULL";
    return s;
}
 
void list::insert(int position, const int& data) {
	if(position < 0 || position > _size) return ;
	if(position != 0 && empty()) return ;
	if(position == 0) {
		node* p;
		p = new node(data, head);
		head = p;
		_size++;
		return ;
	}
	node* p = head;
	for(int i = 1; i < position; i++) {
		p = p->next;
	}
	node* q = p->next;
	p->next = new node(data, q);
	_size++;
}

void list::erase(int position) {
	if(position >=  _size || position < 0) return ;
	if(empty()) return ;
    if(position == 0) {
    	node* k = head->next;
    	delete head;
    	head = k;
    	_size--;
    	return ;
    }
    node* p = head;
	for(int i = 1; i < position; i++) {
		p = p->next;
	}
	node* n = p->next;
	p->next = n->next;
	delete n;
	n = NULL;
	_size--;
}

list& list::sort(void) {
	if(empty()) return *this;
	int temp;
	for(int i = 1; i < size(); i++)
		for(node *p = head; p->next != NULL; p = p->next)
			if(p->data > p->next->data) {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
			}
	return *this;
}


//node* head;
//int _size;