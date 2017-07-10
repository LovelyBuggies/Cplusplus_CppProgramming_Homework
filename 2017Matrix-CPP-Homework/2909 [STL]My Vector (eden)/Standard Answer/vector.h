#ifndef __VECTOR_H__
#define __VECTOR_H__
#define _a Alloc()
#include "base.h"
#include <memory>
#include <cstdio>
template< typename T, typename Alloc = std::allocator<T> >
class myVector : public Base {
    public:
        // Constructor
        myVector() {
            _data = _a.allocate(1);
            _size = 0;
            _capacity = 1;
        }
         myVector(const std::size_t & size, const T & val,
                 Alloc a = Alloc()) {
            _data = a.allocate(size);
            for (std::size_t i = 0; i < size; ++i)
                a.construct(_data + i, val);
            _size = _capacity = size;
        }
        template<typename InputIterator>
            myVector(InputIterator begin, InputIterator end,
                     Alloc a = Alloc()) {
                _size = _capacity = end - begin;
                _data = a.allocate(_size);
                std::size_t cnt = 0;
                for (InputIterator it = begin; it != end; ++it)
                    a.construct(_data + (cnt++), *it);
            }
        myVector(const myVector & other) {
            _size = other._size;
            _capacity = other._capacity;
            _data = _a.allocate(_capacity);
            for (std::size_t i = 0; i < _size; ++i)
                _a.construct(_data + i, other._data[i]);
        }
         // Destructor
        ~myVector() {
            for (std::size_t i = 0; i < _size; ++i)
                _a.destroy(_data + i);
            if (_capacity > 0)
                _a.deallocate(_data, _capacity);
        }
         // Copy Operator
        myVector & operator=(const myVector & other) {
            if (&other != this) {
                std::size_t i;
                for (i = 0; i < _size; ++i)
                    _a.destroy(_data + i);
                if (_capacity > 0)
                    _a.deallocate(_data, _capacity);
                _size = other._size;
                _capacity = other._capacity;
                _data = _a.allocate(_capacity);
                for (i = 0; i < _size; ++i)
                    _a.construct(_data + i, other._data[i]);
            }
            return *this;
        }
         // Iterator
        typedef T *         iterator;
        typedef const T *   const_iterator;
         inline iterator begin() {
            return _data;
        }
        inline const_iterator begin() const {
            return _data;
        }
        inline iterator end() {
            return _data + _size;
        }
        inline const_iterator end() const {
            return _data + _size;
        }
         // Capacity
        inline std::size_t size() const {
            return _size;
        }
        void resize(const std::size_t & newSize) {
            std::size_t i;
            if (newSize <= _size) {
                for (i = newSize; i < _size; ++i)
                    _a.destroy(_data + i);
            } else {
                if (newSize > _capacity) {
                    std::size_t newCapacity = _capacity * 2;
                    while (newSize > newCapacity)
                        newCapacity *= 2;
                    reserve(newCapacity);
                }
                for (i = _size; i < newSize; ++i)
                    _a.construct(_data + i, T());
            }
            _size = newSize;
        }
        void resize(const std::size_t & newSize, const T & val) {
            std::size_t i;
            if (newSize <= _size) {
                for (i = newSize; i < _size; ++i)
                    _a.destroy(_data + i);
            } else {
                if (newSize > _capacity) {
                    std::size_t newCapacity = _capacity * 2;
                    while (newSize > newCapacity)
                        newCapacity *= 2;
                    reserve(newCapacity);
                }
                for (i = _size; i < newSize; ++i)
                    _a.construct(_data + i, val);
            }
            _size = newSize;
        }
        inline std::size_t capacity() const {
            return _capacity;
        }
        inline bool empty() const {
            return _size == 0;
        }
        void reserve(const std::size_t & newCapacity) {
            if (newCapacity > _capacity) {
                T * temp = _a.allocate(newCapacity);
                for (std::size_t i = 0; i < _size; ++i) {
                    _a.construct(temp + i, _data[i]);
                    _a.destroy(_data + i);
                }
                _a.deallocate(_data, _capacity);
                _capacity = newCapacity;
                _data = temp;
            }
        }
         // Element Access
        inline T & operator[](const std::size_t & index) {
            return _data[index];
        }
        inline const T & operator[](const std::size_t & index) const {
            return _data[index];
        }
        inline T & front() {
            return _data[0];
        }
        inline const T & front() const {
            return _data[0];
        }
        inline T & back() {
            return _data[_size - 1];
        }
        inline const T & back() const {
            return _data[_size - 1];
        }
        inline T * data() {
            return _data;
        }
        inline const T * data() const {
            return _data;
        }
         // Modifiers
        template<typename InputIterator>
            void assign(InputIterator begin, InputIterator end) {
                std:size_t newSize = 0;
                InputIterator it;
                for (it = begin; it != end; ++it)
                    ++newSize;
                if (newSize > _capacity) {
                    std::size_t newCapacity = _capacity * 2;
                    while (newSize > newCapacity)
                        newCapacity *= 2;
                    reserve(newCapacity);
                }
                std::size_t i;
                for (i = 0; i < _size; ++i)
                    _a.destroy(_data + i);
                for (i = 0, it = begin; i < newSize; ++i, ++it)
                    _a.construct(_data + i, *it);
                _size = newSize;
            }
        void assign(const std::size_t & newSize, const T & val) {
            if (newSize > _capacity) {
                std::size_t newCapacity = _capacity * 2;
                while (newSize > newCapacity)
                    newCapacity *= 2;
                reserve(newCapacity);
            }
            std::size_t i;
            for (i = 0; i < _size; ++i)
                _a.destroy(_data + i);
            for (i = 0; i < newSize; ++i)
                _a.construct(_data + i, val);
            _size = newSize;
        }
        void push_back(const T & val) {
            if (_size >= _capacity)
                reserve(_capacity * 2);
            _a.construct(_data + (_size++), val);
        }
        void pop_back() {
            _a.destroy(_data + (--_size));
        }
        void clear() {
            for (std::size_t i = 0; i < _size; ++i)
                _a.destroy(_data + i);
            _size = 0;
        }
     private:
        T * _data;
        std::size_t _size, _capacity;
};
 #endif
