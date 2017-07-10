//
// List.cpp
// C++
//
// Created by Nino Leo on 2017/06/03.
// Copyright © Nino 2017. All rights reserved.
//

#ifndef _LIST_HPP_
#define _LIST_HPP_
#define E int

#include "Collection.hpp"


class List : public Collection
{
public:
	List() {}
	virtual~List() {}
    virtual void add(E e) = 0;
    virtual void clear(void) = 0;
    virtual bool contain(E e) = 0;
    virtual bool isEmpty(void) = 0;
    virtual void remove(E e) = 0;
    virtual E& operator[](int index) = 0;
    virtual E& get(int index) = 0;
    virtual int indexOf(E element) = 0;
    virtual void sort(void) = 0;
    virtual int size(void) = 0;
};

#endif