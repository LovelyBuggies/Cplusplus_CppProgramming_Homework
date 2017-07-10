#include "list.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

list::list(){
	_size=0;
	head=0;
	empty_head=0;
}
list::list(const list& another)
{
	head=another.head;
    empty_head=another.empty_head;
    _size=another.size();
    for(int i=0;i<another.size();i++){
    	storage[i].data=another.storage[i].data;
    }
}
list& list::operator=(const list&another)
{
    head=another.head;
    empty_head=another.empty_head;
    _size=another.size();
    for(int i=0;i<another.size();i++){
    	storage[i].data=another.storage[i].data;
    }
    return (*this);
}
list::~list(){}

// Capacity    
bool list::empty(void) const
{
	if(head==0) return true;
	else return false;
}
unsigned int list::size(void) const
{
	return _size;
}

// output
// list: [1,2,3,4,5]
// output: 1->2->3->4->5->NULL 
std::string list::toString(void) const
{
	string k="";
	for(int i=0;i<_size;i++){
		cout<< storage[i].data << "->";
	}
	cout << "NULL";
	return k;
}

void list::insert(int position, const int& data)
{
   if(position <= _size && _size <MAX_STORAGE)
  { for(int i = _size;i > position;i--)
    { storage[i].data = storage[i - 1].data;
    }
    storage[position].data = data;
    _size++;
  }

}

void list::erase(int position)
{ 
  if(position >= _size || position > 1000) return;
  for(int i = position;i < _size - 1;i++)
  storage[i].data = storage[i + 1].data;
  --_size;
  
}

void list::clear(void)
{
    for(int i=_size;i>0;i--){
    	erase(0);
    }
}

list& list::sort(void)
{
	data_type temp;
  if(_size == 0) return *this;
	for(int k=1;k<=_size-1;k++)
	for(int i=1;i<_size-k+1;i++)
		if(storage[i-1].data>storage[i].data){
            temp=storage[i-1].data;
            storage[i-1].data=storage[i].data;
            storage[i].data=temp;
		}
	return (*this);
}



