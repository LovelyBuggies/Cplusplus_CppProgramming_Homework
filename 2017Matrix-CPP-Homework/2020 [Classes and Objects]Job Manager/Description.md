# [Classes and Objects]Job Manager

## Description
In this assignment, you are required to finish two classes' definition
according to their declaration respectly.  
1\. Two basic concepts are needed before you begin to code: 1. Singleton, 2.
linked Queue.

SINGLETON: Singleton is a kind of frequently-used Design Pattern(but often be prone to misuse).  
    Ensure a class only has one instance, and provide a global point of access to it.  
    Use the Singleton pattern when  
- there must be exactly one instance of a class, and it must be accessible to clients from a wellknown access point.  
- when the sole instance should be extensible by subclassing, and clients should be able to use an extended instance without modifying their code.  

2\. Class Job has:  
(1)one static variable "number", which indicates current object's id. you shold increment it when you create an new object.        Attention: when the object was destoyed, this variable do not subtract by 1;  
(2)three memeber variables:    
- id means this object's id. you need to set the current number to id when create an object. 
- priority, means the importance among all jobs.
- nextJob, a Job pointer, which points to the next Job.    

(3)function toString return a string, its format is like: [id:priority], for example: [0:234]..

3\. Class JobManager only has one instance, JobManager can manage the jobs in
the job queue.  
    JobManager manages the job queue according to the principle FIFO(First In, First Out), **no matter what the priority is**..  
    This Class has a member variable named "jobFrontPointer"(Job *), which points to the first Job in the queue(first add).  
static variable instance is the only instance of this class. You need to
implement two static function getInstance and deleteInstance. "getInstance"
will return the only instance of this class; "deleteInstance" will delete the
only instance, if delete successfully, return true; otherwise, return false.   
```
  void addJob(int pri = 0); which adds one job(its priority is pri, default: 0) to the end of queue.  
  void finishOneJob(); which finish the job in the begin and pop it out of the queue.  
  void sortJob(); which sorts the current queue according to their priority (if same, then the smaller id is in front of the larger one).  
  void printJob(); print the queue's job, like "[2:23432]->[3:1]->[4:5]->[5:0]->[6:6666]" with endl.  
  int getNumOfJob(); return the number of jobs in the queue.  
  void clear(); clear the queue.
```

## Hint
**singleton and linked queue..**

## Attention:
the declaration of Job has changed by younglee, add method getter and setter for member variable "id"....   
*出题人：黎洋*
