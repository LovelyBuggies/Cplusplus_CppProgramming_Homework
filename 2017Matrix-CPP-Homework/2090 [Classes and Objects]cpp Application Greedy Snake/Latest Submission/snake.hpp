#ifndef snake_hpp
#define snake_hpp

#include <iostream>
#include "global.hpp"
#include <algorithm>
#include <list>
#include <cstring>
#define MAX_BODY_LENGTH 60

typedef struct snake {

    point _head;
    point _tail;
    point _body [MAX_BODY_LENGTH];
    int _length;
    
    snake (point P) {
        _head = _tail = P;
        for (int i = 0; i < MAX_BODY_LENGTH; ++i)
            _body[i].x = _body[i].y = -1;
        _length = 0;
    }
    
    void snakeGrowth() { _body[_length++] = _tail; }
    
    void snakeMovement(direction d) {
        if (_length != 0) 
            _tail = _body[_length - 1];
        else 
            _tail = _head;
        for (int i = _length - 1; i > 0; --i)
            _body[i] = _body[i - 1];
        _body[0] = _head;
        _head.move(d);
    }


} snake;


#endif