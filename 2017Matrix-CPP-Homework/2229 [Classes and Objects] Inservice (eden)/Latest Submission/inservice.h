#include <iostream>
#include <string>

using namespace std;



class Person
{
private:
	string _name;
	int _sex;

public:
	Person(string name, int sex):_name(name),_sex(sex) { cout << "Construct Person"<< endl;}

	string getName(void ) { return _name;}

	string getSex(void) { return ( _sex == 1)? "1" : "0"; }
	
  ~Person(){cout << "Destruct Person"<< endl;}
};



class Student : virtual public Person
{
private:
	string _sno;
  
public:
	Student(string name, int sex, string sno) : Person(name, sex), _sno(sno) { cout <<"Construct Student"<< endl;}
	
  string getSno(void ) { return _sno; }
  
  ~Student() { cout <<"Destruct Student"<< endl; }
};



class Worker : virtual public Person
{
private:
	string _wno;
  
public:
	Worker(string name, int sex, string wno) : Person(name, sex), _wno(wno) { cout <<"Construct Worker" << endl; }

	string getWno(void ) { return _wno; }
	
  ~Worker(){ cout <<"Destruct Worker" << endl; }
};


class InService : public Student, public Worker
{
public:
	InService(string name, int sex, string sno, string wno) : Student(name, sex, sno),Worker(name, sex, wno), Person(name, sex) { cout << "Construct InService"<< endl; }
	~InService() { cout << "Destruct InService"<< endl; }
};
