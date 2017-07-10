//
//animal.h
//C++
//
//Created by Nino on 17/04/21
//Copyright ©Nino 2017. All right reserved.
//

#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>
#include <string>

using namespace std;


enum Type {CAT, DOG};

class Animal {
 public:
  Animal(string _name, int _age) : name(_name), age(_age) { }
    
  virtual void Shout() const = 0;
    
  virtual Type getType() const = 0;
    
  std::string getName() const { return name; }

  int getAge() const { return age; }
  
 protected:
    std::string name;
    int age;
};



class Cat : public Animal{
public:
	Cat(string _name = "", int _age = 0) : Animal(_name, _age) { }
  
  //watch out for the const, when losing it would be a redefinition not polymorphism
	virtual void Shout() const { cout << getName() << ": meow~~" << endl; }
  
 //watch out for the const, when losing it would be a redefinition not polymorphism
	virtual Type getType() const { return CAT; }
};



class Dog : public Animal{
public:
	Dog(string _name = "", int _age = 0) : Animal(_name,_age) { }
  
 //watch out for the const, when losing it would be a redefinition not polymorphism
	virtual void Shout() const { cout << getName() << ": bark!!" << endl; }
  
//watch out for the const, when losing it would be a redefinition not polymorphism
	virtual Type getType() const { return DOG; }
};

#endif