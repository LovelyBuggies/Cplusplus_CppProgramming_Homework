 
//
// List.cpp
// C++
//
// Created by Nino Leo on 17/5/12.
// Copyright © Nino 2017. All rights reserved.
//

#define NULL 0

#include "List.hpp"
#include <string>
#include <ostream>
#include <sstream>

using namespace std;


// default constructor
list::list() {
  head = tail = NULL;
  _size = 0;
}

// creat a list from an exist array
list::list(const list::data_type a[], int length) {
  head = tail = NULL;
  _size = 0;
  this->assign(a, length);
}

list::list(const list& other) {
  head = tail = NULL;
  _size = 0;
  this->assign(other);
}



// asignment

list& list::operator=(const list& other) {
  this->assign(other);
  return *this;
}
list::~list() {
  clear();
}



// Capacity

bool list::empty(void) const {
  return (_size == 0)? true : false;
}
list::size_type list::size(void) const {
  return _size;
}



// Element access

list::data_type& list::front(void) const {
    return head->data;
}
list::data_type& list::back(void) const {
    return tail->data;
}



// output format

// NULL<-1<->2<->3<->4<->5->NULL

// NULL<-1->NULL

// NULL 

std::string list::toString(void) const {
  stringstream out;
  string ret;
  out << "NULL";
  if(this->empty()) return "NULL";
  out << "<-";
  list::node *p = this->head;
  while(p->next)
  {
    out << p->data << "<->";
    p = p->next;
  }
  out << p->data << "->NULL";
  out >> ret;
  return ret;
}



// Modifiers

void list::assign(const list& other) {
  if(&other == this) return ;
  this->clear();
  head = tail = NULL;
  _size = 0;
  _size = other._size;
  if(_size == 0) {
    head = tail = NULL;
    return ;
  }
  head = new node(other.head->data, 0, 0);
  node* p = other.head->next;
  node* q = this->head;
  while(p) {
      q->next = new node(p->data, 0, q);
      q = q->next;
      p = p->next;
  }
  tail = q;
}

void list::assign(const list::data_type datas[], int length) {
  this->clear();
  head = tail = NULL;
  _size = 0;
  head = tail = NULL;
  _size = 0;
  for(int i = 0; i < length; ++i)
    this->push_back(datas[i]);
}



void list::push_front(const list::data_type& temp) {
  if(_size == 0) {
    head = new node(temp, 0, 0);
    tail = head;
    _size++;
    return;
  }
  node *p = new node(temp, head, 0);
  head->prev = p;
  head = p;
  _size++;
}

void list::push_back(const list::data_type& temp) {
  if(_size == 0) {
    head = new node(temp, 0, 0);
    tail = head;
    _size++;
    return;
  }
  node *p = new node(temp, 0, tail);
  tail->next = p;
  tail = p;
  _size++;
}

void list::pop_front(void) {
  if(_size == 0) 
    return;
  if(tail == head) {
    clear();
    return;
  }
  node *p = head->next;
  delete head;
  p->prev = NULL;
  head = p;
  _size--;
}

void list::pop_back(void) {
  if(_size == 0) 
    return;
  if(tail == head) {
    clear();
    return;
  }
  node *p = tail->prev;
  delete tail;
  p->next = NULL;
  tail = p;
  _size--;
}


void list::insert(int position, const list::data_type& data) {
  if(position == 0) {
    push_front(data);
    return ;
  }
  if(position == _size) {
    push_back(data);
    return ;
  }
  node *p = at(position);
  if(p == NULL)
    return ; 
  node *q = new node(data, p, p->prev);
  p->prev->next = q;
  p->prev = q;
  _size++;
}

void list::erase(int position) {
  if(position == 0) {
    this->pop_front();
    return ;
  }
  if(position == _size-1) {
    this->pop_back();
    return ;
  }
  node *p = at(position);
  if(p == NULL)
    return ;
  p->next->prev = p->prev;
  p->prev->next = p->next;
  delete p;
  _size--;
}

void list::clear(void) {
  node *p = head;
  while(p) {
    node *q = p->next;
    delete p;
    p = q;
  }
  head = tail = 0;
  _size = 0;
}






// Operations

// split this list into to lists at the given position

void list::split(int position, list* des1, list* dest2) {
  list cpy(*this);
  des1->clear();
  dest2->clear();
  for(int i = 0; i < position; ++i) {
    des1->push_back(cpy.front());
    cpy.pop_front();
  }
  for(int i = 0; i < _size - position; ++i) {
    dest2->push_back(cpy.front());
    cpy.pop_front();
  }
}



// merge two list to this list from src1 and src2

list& list::merge(const list& src1, const list& src2) {
  int s1 = src1.size();
  int s2 = src2.size();
  list cpy1(src1);
  list cpy2(src2);
  this->clear();
  for(int i = 0; i < s1; ++i) {
    this->push_back(cpy1.front());
    cpy1.pop_front();
  }
  
  for(int i = 0; i < s2; ++i) {
    this->push_back(cpy2.front());
    cpy2.pop_front();
  }
  return *this;
}



// remove the elements who satisfy the condition

list& list::remove_if(bool (*condition)(list::listPointer)) {
listPointer p = this->head;
  while (p != NULL) {
    if (condition(p)) {
      if (p == this->head) {
        this->head = this->head->next;
        if (this->head != NULL) {
          this->head->prev = NULL;
        }
        delete p;
        this->_size--;
        p = this->head;
        if (p == NULL) {
          this->tail = NULL;
        }
      } else if (p == this->tail) {
        this->tail = this->tail->prev;
        this->tail->next = NULL;
        delete p;
        this->_size--;
        p = NULL;
      } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        listNode* q = p->next;
        delete p;
        p = q;
        this->_size--;
      }
    } else {
      p = p->next;
    }
  }
  return *(this);
}



// remove duplicate elements

list& list::unique(void) {
  listPointer p, q;
  p = head;
  while (p != NULL) {
    q = p->next;
    while (q != NULL) {
      if (q->data == p->data) {
        if (q == head) {
          head = head->next;
          if (head != NULL) 
            head->prev = NULL;
          else 
            tail = NULL;
          q = head;
        } 
        else if (q == tail) {
          tail = tail->prev;
          tail->next = NULL;
          delete q;
          q = NULL;
        } 
        else {
          q->next->prev = q->prev;
          q->prev->next = q->next;
          listPointer temp = q;
          q = q->next;
          delete temp;
        }
        _size--;
      } 
      else 
        q = q->next;
    }
    p = p->next;
  }
  return *this;
}


// reverse the list

list& list::reverse(void) {
  list temp(*this);
  this->clear();
  while(!temp.empty()) {
    this->push_back(temp.back());
    temp.pop_back();
  }
  return *this;
}



// operators

list::data_type& list::operator[](int index) {
  return at(index)->data;
}

list& list::operator+=(const list& add) {
  list temp(*this);
  this->clear();
  this->assign(merge(temp, add));
  return *this;
}



// output

std::ostream& operator<<(std::ostream& out, const list& li) {
  out << "NULL";
  if(li.empty()) return out;
  out << "<-";
  list::node *p = li.head;
  while(p->next)
  {
    out << p->data << "<->";
    p = p->next;
  }
  out << p->data << "->NULL";
  return out;
}
