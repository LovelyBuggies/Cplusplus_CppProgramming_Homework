#include "DouList.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

DouList::DouList(){
    m_head = m_tail = NULL;
}
    
DouList::DouList(const DouList &src){
    if(src.m_head != 0){
        m_head=new DouListNode(src.m_head->elem,0,0);
    DouListNode *p=src.m_head;
    DouListNode *q=m_head;
    while(p->next != 0){
        p=p->next;
        q->next=new DouListNode(p->elem,q,0);
        q=q->next;
    }
    m_tail=q;
    }
}
    
DouList::~DouList(){
    clear();
}
    
void DouList::clear(){
    DouListNode *p=m_head;
    if(p==NULL) return;
    DouListNode *q;
    while(p->next){
      q=p->next;
      delete p;
      p=q;
    }
    delete p;
  m_head=NULL;
  m_tail=NULL;
}

bool DouList::empty() const{
    return (m_head == NULL) ? 1:0;
}

string DouList::to_str() const{
    string r="[";
    string s;
    char str[5];
    DouListNode *p=m_head;
    if(p!=NULL){
    while(p->next != 0){
        sprintf(str,"%d",p->elem);
        s=str;
        r=r+s+", ";
        p=p->next;
    }
    sprintf(str,"%d",m_tail->elem);
    s=str;
    r=r+s;}
    r=r+"]";
    return r;
}
    
int DouList::front() const{
    if(m_head==0) return -1;
    return m_head->elem;
}
    
int DouList::back() const{
    if(m_tail==0) return -1;
    return m_tail->elem;
}
    
void DouList::push_front(const int &e){
    DouListNode *p;
    if(m_head==0){
        m_head=new DouListNode(e,0,0);
        m_tail=m_head;
        return;
    }
    p=new DouListNode(e,0,m_head);
    m_head->prev=p;
    m_head=p;
}

void DouList::push_back(const int &e){
    DouListNode *p;
    if(m_tail==0){
        m_tail=new DouListNode(e,0,0);
        m_head=m_tail;
        return;
    }
    p=new DouListNode(e,m_tail,0);
    m_tail->next=p;
    m_tail=p;
}
    
void DouList::pop_front(){
    DouListNode *p;
    p=m_head->next;
    p->prev=0;
    delete m_head;
    m_head=p;
}

void DouList::pop_back(){
    DouListNode *p;
    p=m_tail->prev;
    p->next=0;
    delete m_tail;
    m_tail=p;
}

DouList& DouList::operator=(const DouList &other){ 
  if(this==&other) return *this;
  DouList src(other);
  clear();
    if(src.m_head != 0){
        m_head=new DouListNode(src.m_head->elem,0,0);
    DouListNode *p=src.m_head;
    DouListNode *q=m_head;
    while(p->next != 0){
        p=p->next;
        q->next=new DouListNode(p->elem,q,0);
        q=q->next;
    }
    m_tail=q;
    }
    return *this;
}
    
ostream& operator<<(ostream &out,
           const DouList &list){
    DouListNode *p=list.m_head;
    out << "[";
    if(p!=NULL){    
    while(p->next != 0){
        out << p->elem << ", ";
        p=p->next;
    }
    out << p->elem;
    }
    out << "]";
    return out;
}