#include "JobManager.h"
#include<iostream>
using namespace std;

JobManager* JobManager::instance;

JobManager::JobManager()
{
  jobFrontPointer=NULL;
}
    
JobManager::~JobManager()
{
    clear();
}

JobManager* JobManager::getInstance()
{  
  if(instance==NULL)
    instance=new JobManager();
  return instance;
}
        
bool JobManager::deleteInstance()
{
  bool r=false;
  if(instance!=NULL) {
    delete instance; 
    instance=NULL;
    r=true;
  }
  return r;
}

void JobManager::addJob(int priority)
{
  Job *pointer=NULL;
  if(jobFrontPointer==NULL)
  {jobFrontPointer=new Job(priority); return;}
  pointer=jobFrontPointer;
  while(pointer->getNext()!=NULL)
  pointer=pointer->getNext();
  pointer->setNext(new Job(priority));
}
        
void JobManager::finishOneJob()
{
  if(jobFrontPointer==NULL) return;
  Job *pointer=jobFrontPointer;
  jobFrontPointer=jobFrontPointer->getNext();
  delete pointer;
  pointer=NULL;
}
        
void JobManager::sortJob()
{
   Job *p=NULL,*q=NULL;
   int tempid,temppriority;
   for(p=jobFrontPointer;p!=NULL;p=p->getNext())
    for(q=p->getNext();q!=NULL;q=q->getNext())
      if((p->getPriority() < q->getPriority())||(p->getPriority() == q->getPriority()&&p->getId()>q->getId()))
        {
        tempid=p->getId();
        temppriority=p->getPriority();
        p->setId(q->getId());
        p->setPriority(q->getPriority());
        q->setId(tempid);
        q->setPriority(temppriority);
      }
}
        
void JobManager::printJob()
{
  if(jobFrontPointer==NULL) return;
  Job *pointer=jobFrontPointer;
  while(pointer!=NULL) 
  {
    cout << pointer->toString();
    pointer=pointer->getNext();
    if(pointer!=NULL) cout << "->";
  }
  cout<<endl;
}
        
int JobManager::getNumOfJob()
{
  Job *pointer=jobFrontPointer;
  int num=0;
  while(pointer!=NULL)
  {
    num++;
    pointer=pointer->getNext();
  }
  if(!num)
    cout<<"empty!"<<endl;
  return num;
}
        
void JobManager::clear()
{
  if(jobFrontPointer==NULL) return;
  Job *p=jobFrontPointer;
  Job *q=p->getNext();
  delete p;
  p=NULL;
  jobFrontPointer=NULL;
  while(q!=NULL)
  {
    p=q;
    q=p->getNext();
    delete p;
    p=NULL;
  }
}
