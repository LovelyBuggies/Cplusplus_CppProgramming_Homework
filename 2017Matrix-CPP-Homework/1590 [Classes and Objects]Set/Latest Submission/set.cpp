#include "set.hpp"   

Set::Set( ){ size = 0; }

Set::Set(int* m, int s) {
  size = 0;
  for(int i = 0; i < s; i++)
    if(!isInSet(*(m+i)))
     members[size++]=*(m+i);
}

bool Set::append(int e) {
  if(isInSet(e)) return false;
  	members[size++]=e;
	return true;
}

bool Set::remove(int e) {
  if(!isInSet(e)) return false;
  for(int i=0;i<size;i++)
    if(*(members+i)==e)
     {
      int temp = *(members+size-1);
      *(members+size-1) = *(members+i);
      *(members+i) = temp;
      size--;
     }
  return true;
}

bool Set::isEmptySet() { return (size == 0)? true : false; }
    
int* Set::getMembers() { return members; }
    
int Set::getSize() { return size; }
 
bool Set::isInSet(int e) {
  for(int i = 0; i < size; i++)
   if(*(members+i)==e)
     return true;
  return false;
}