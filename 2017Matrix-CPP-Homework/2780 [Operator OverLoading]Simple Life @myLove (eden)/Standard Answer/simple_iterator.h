#ifndef SIMPLE_ITERATOR_H
#define SIMPLE_ITERATOR_H

#include <iostream>
using namespace std;

#define EOT 4
#define NUL 0

class simple_iterator {
    char* pointer;
  public:
    simple_iterator() { }

    explicit simple_iterator(char * c) {
        pointer = c;
    }

    ~simple_iterator() { }

    char& base() const { return *pointer; }

    char operator*() {
        return *pointer;
    }

    simple_iterator& operator++() {
        ++pointer;
        return *this;
    }

    simple_iterator& operator--() {
        --pointer;
        return *this;
    }

    simple_iterator operator++(int) {
        simple_iterator __tmp = *this;
        ++pointer;
        return __tmp;
    }

    simple_iterator operator--(int) {
        simple_iterator __tmp = *this;
        --pointer;
        return __tmp;
    }

    simple_iterator prev() {
        simple_iterator __tmp = *this;
        return --__tmp;
    }

    simple_iterator next() {
        simple_iterator __tmp = *this;
        return ++__tmp;
    }


    simple_iterator begin() {
        simple_iterator __tmp = *this;
        simple_iterator __ans = __tmp;
        while (*__tmp != '\0') {
            __ans = __tmp;
            __tmp = __tmp.prev();
        }
        return __ans;
    }

    simple_iterator end() {
        simple_iterator __tmp = *this;
        simple_iterator __ans = __tmp;
        while (*__tmp != NUL) {
            __ans = __tmp;
            __tmp = __tmp.next();
        }
        return __ans;
    }
};

inline bool operator==(const simple_iterator& __x,
    const simple_iterator& __y)
{ return __x.base() == __y.base(); }

inline bool operator!=(const simple_iterator& __x,
    const simple_iterator& __y)
{ return !(__x == __y); }

inline bool operator<(const simple_iterator& __x,
    const simple_iterator& __y)
{ return __x.base() < __y.base(); }

inline bool operator>(const simple_iterator& __x,
    const simple_iterator& __y)
{ return __x.base() > __y.base(); }

inline bool operator<=(const simple_iterator& __x,
    const simple_iterator& __y)
{ return !(__x > __y); }

inline bool operator>=(const simple_iterator& __x,
    const simple_iterator& __y)
{ return !(__x < __y); }

inline simple_iterator operator+(const simple_iterator& __x,
    const int& __n) {
    simple_iterator __tmp = __x;
    for (int i = 0; i < __n; i++)
        ++__tmp;
    return __tmp;
}

inline simple_iterator operator-(const simple_iterator& __x,
    const int& __n) {
    simple_iterator __tmp = __x;
    for (int i = __n; i > 0; i--)
        --__tmp;
    return __tmp;
}

#endif

