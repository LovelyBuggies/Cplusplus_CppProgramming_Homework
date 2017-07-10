 // 
// vector.h
// CPP
// Created by Nino Leo on 2017/06/09.
// Copyright © Nino 2017. All rights reserved.
//



#ifndef _VECTOR_H_
#define _VECTOR_H_
#define EXPAND_FACTOR 2
#define DAFAULT_VAL 0
#include "test.h"
#include "base.h"
#include <iostream>

using std::cout;
using std::endl;


template< typename T, typename Alloc = std::allocator<T> >
class myVector : public Base {
   public:

      // Constructors and Destructor
      
      myVector() {
         _size = 0;
         testAllocator temp;
         _data = temp.allocate(_size);
         temp.deallocate(_data, _size);
         _capacity = 1;
      }
      
      myVector(const std::size_t& size, const T& val,
               Alloc a = Alloc()) {
         _size = size;
         while(_capacity < size) {
            _capacity *= EXPAND_FACTOR;
         }
         _data = a.allocate(_size);
         a.construct(_data, val);
         for(int i = 0; i < _size; i++) {
            _data[i] = val;
         }
      }
      
      template<typename InputIterator>
      myVector(InputIterator begin, InputIterator end,
               Alloc a = Alloc()) {
         _size = end - begin;
         while(_capacity < _size) {
            _capacity *= EXPAND_FACTOR;
         }
         _data = new T [_capacity];
         int index = 0;
         for(InputIterator it = begin; it < end; ++it, ++index) {
            _data[index] = *it;
         }
      }
      
      template<typename InputIterator>
      myVector(const myVector & other) {
         _size = other.size();
         while(_capacity < _size) {
            _capacity *= EXPAND_FACTOR;
         }
         _data = new T [_capacity];
         for(InputIterator it = other.begin(), index = 0; it <other.end(); ++it, ++index) {
            _data[index] = *it;
         }
      }
      
      ~myVector() {
         this->clear();
      } 
         
      
      
      // Copy Operator
      
      template<typename InputIterator>
      myVector & operator=(const myVector & other) {
         this->clear();
         _size = _capacity = other.size();
         _data = new T [_capacity];
         int index = 0;
         for(InputIterator it = other.begin(); it <other.end(); ++it, ++index) {
            _data[index] = *it;
         }
      }



      // Iterator
      
      typedef T* iterator;
      typedef const T* const_iterator;
      inline iterator begin() {
         if(this->empty())
            return NULL;
         else
            return _data;
      }
      
      inline const_iterator begin() const {
         if(this->empty())
            return NULL;
         else
            return _data;
      }
      
      inline iterator end() {
         if(this->empty())
            return NULL;
         else
            return _data + _size - 1;
      }
      
      inline const_iterator end() const {
         if(this->empty())
            return NULL;
         else
            return _data + _size - 1;
      }



      // Capacity
      
      inline std::size_t size() {
         return _size;
      }
      
      void resize(const std::size_t& newSize) {
         if(newSize == _size)
            return ;
         std::size_t  newCapacity = 1;
         while(newCapacity < newSize) {
            newCapacity *= EXPAND_FACTOR;
         }
         T * newData = new T [newCapacity];
         if(newSize < _size)
            for(int i = 0; i < newSize; ++i) {
               newData[i] = _data[i];
            }
         else {
            for(int i = 0; i < _size; ++i)
               newData[i] = _data[i];
            for(int i = _size; i < newSize; ++i)
               newData[i] = DAFAULT_VAL;
         }
         delete [] _data;
         _data = newData;
         _size = newSize;
         _capacity = newCapacity;
      }
      
      void resize(const std::size_t& newSize, const T& val) {
         if(newSize == _size)
            return ;
         std::size_t  newCapacity = 1;
         while(newCapacity < newSize) {
            newCapacity *= EXPAND_FACTOR;
         }
         T * newData = new T [newCapacity];
         if(newSize < _size)
            for(int i = 0; i < newSize; ++i) {
               newData[i] = _data[i];
            }
         else {
            for(int i = 0; i < _size; ++i)
               newData[i] = _data[i];
            for(int i = _size; i < newSize; ++i)
               newData[i] = val;
         }
         delete [] _data;
         _data = newData;
         _size = newSize;
         _capacity = newCapacity;
      }
      
      inline std::size_t capacity() const {
         return _capacity;
      }
      
      inline bool empty() const {
         return (_size == 0)? true : false;
      }
      
      void reserve(const std::size_t& newCapacity) {
         T * newData = new T [newCapacity];
         for(int i = 0; i < _size; ++i)
            newData[i] = _data[i];
         delete [] _data;
         _data = newData;
         _capacity = newCapacity;
      }



      // Element Access
      
      inline T& operator[](const std::size_t& index) {
         return _data[index];
      }
      
      inline const T& operator[](const std::size_t& index) const {
         return _data[index];
      }
      
      inline T& front() {
         if(this->empty())
            return DAFAULT_VAL;
         else
            return *_data;
      }
      
      inline const T& front() const {
         if(this->empty())
            return DAFAULT_VAL;
         else
            return *_data;
      }
      
      inline T& back() {
         if(this->empty())
            return DAFAULT_VAL;
         else
            return *(_data+_size-1);  
      }
      
      inline const T& back() const {
         if(this->empty())
            return DAFAULT_VAL;
         else
            return *(_data+_size-1);
      }
      
      inline T* data() {
         return _data;
      }
      
      inline const T* data() const {
         return _data;
      }
      


      // Modifiers
      
      template<typename InputIterator>
      void assign(InputIterator begin, InputIterator end) {
         _size = end - begin;
         while(_capacity < _size) {
            _capacity *= EXPAND_FACTOR;
         }
         _data = new T [_capacity];
         int index = 0;
         for(InputIterator it = begin; it < end; ++it, ++index) {
            _data[index] = *it;
         }
      }
      
      void assign(const std::size_t& newSize, const T& val) {
         if(newSize == _size)
            return ;
         std::size_t  newCapacity = 1;
         while(newCapacity < newSize) {
            newCapacity *= EXPAND_FACTOR;
         }
         T * newData = new T [newCapacity];
         if(newSize < _size)
            for(int i = 0; i < newSize; ++i) {
               newData[i] = _data[i];
            }
         else {
            for(int i = 0; i < _size; ++i)
               newData[i] = _data[i];
            for(int i = _size; i < newSize; ++i)
               newData[i] = val;
         }
         delete [] _data;
         _data = newData;
         _size = newSize;
         _capacity = newCapacity;
      }
      
      void push_back(const T& val) {
         resize(_size+1, val);
      }
      void pop_back() {
         resize(_size-1);
      }
      void clear() {
         delete [] _data;
         _size = _capacity = 0;
      }
     private:
        T* _data;
        std::size_t _size, _capacity;
};

#endif