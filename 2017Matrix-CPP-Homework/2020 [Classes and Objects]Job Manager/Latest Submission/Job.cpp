#include "Job.h"
#include <string>
#include <cstdio>
int Job::number=0;

Job::Job(int priority)
{
  nextJob=NULL;
  id=number++;
  this->priority=priority;
}
        
void Job::setId(int id)
{
  this->id=id;
}
        
int Job::getId() const
{
  return id;
}
        
void Job::setPriority(int priority)
{
  this->priority=priority;
}
        
int Job::getPriority() const
{
  return priority;
}
        
void Job::setNext(Job *job)
{
  this->nextJob=job; 
}
        
Job *Job::getNext() const
{
  return nextJob;
}
        
string Job::toString()
{
  string ans;
  char temp[200]={0};
  sprintf(temp,"[%d:%d]",id,priority);
  ans.append(temp);
  return ans;
}
