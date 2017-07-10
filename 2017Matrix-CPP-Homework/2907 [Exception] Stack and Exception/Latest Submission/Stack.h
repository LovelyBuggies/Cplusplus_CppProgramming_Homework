// 
// Stack.h
// C++
// Created by Nino Leo on 2017/06/09.
// Copyright © Nino 2017. All rights reserved.
//


#ifndef STACK_H
#define STACK_H

const int MAX_LEN = 5;

template<class T>
class Stack {
public:
    
  explicit Stack() { stack_size = 0; }
	
  bool empty() const { return (stack_size == 0)? true : false;	}
    
  int size() const { return stack_size; }

  T& top() {
    if(empty()) 
    	throw 1;
    return data[stack_size-1];
  }

  const T& top() const {
    	if(this->empty()) 
        throw 1;
    return data[stack_size-1];
  }
    
  void push(const T& x) {
    	    if (stack_size == MAX_LEN) {
        if (!(top() < x))
            return;
        stack_size--;
    }
    data[stack_size++] = x;
  }
    
  void pop() {
    if(this->empty())
    	throw 0.1;
    stack_size--;
  }
  
private:
    T data[MAX_LEN];
    int stack_size;
};

#endif