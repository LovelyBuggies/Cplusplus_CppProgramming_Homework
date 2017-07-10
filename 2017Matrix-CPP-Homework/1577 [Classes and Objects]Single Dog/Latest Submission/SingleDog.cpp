//DeepCopy and ShallowCopy

#include "SingleDog.h"

#include <cstring>

int SingleDog::count=0;      
//count as static variable not belong to any class
//so we need to initialize it 

SingleDog::SingleDog(int id_, char* name_):id(id_)
{
  int s=20;
  name=new char[s];
  strcpy(name,name_);
//value passes not address passes
  count++;
}

SingleDog::SingleDog(const SingleDog &other):id(other.id)
{
  count++;
  name=new char[20]; 
  strcpy(name,other.name);
//value passes not address passes
}
//copy constructor
//for Deepcopy

SingleDog::~SingleDog()
{
  delete [] name;
  count--;
}
//destructor

int SingleDog::getCount()
//need't static int at all
{
  return count;
}

//Why shall we use DSC?
//When we copy one to another, a pointer in objA was changed and points to the same memory as objB.
//When pointerB was deleted, objA's pointer points to anywhere. This seems dangerous!
//If we put the pointer dynamic, these two pointers are seperated.


