//
//
// C++ game greedy snake
// map.hpp
// 
// Created by Nino Leo on 2017/07/09.
// Copyright © Nino 2017. All rights reserved.
//
//

#ifndef MAP_HPP
#define MAP_HPP

#include "snake.hpp"

#define STATIC_STATUS 0
#define ENLARGE_STATUS 1
#define DEAD_STATUS 2

using std::cout;
using std::endl;
using std::find;

class map {
public:

    map(const point& iSize, const point& iHead, const std::list<point>& iFoods) : 
                _size(iSize), _player(iHead), _foods(iFoods) {
        status = STATIC_STATUS;
        _map = new char*[_size.x];
        for (int i = 0; i < _size.x; ++i) {
            _map[i] = new char[_size.y];
            memset(_map[i], EMPTY, _size.y);
        }
        renewMap();
    }

    ~map() {
        for (int i = 0; i < _size.x; ++i)
            delete [] _map[i];
        delete [] _map;
    }

    void judge() {
        for (int i = 0; i < _player._length; ++i)
            if (_player._head.x == _player._body[i].x && _player._head.y == _player._body[i].y) {
                status = DEAD_STATUS;
                return;
            }
        if (_player._head.x < 0 || _player._head.x >= _size.x || _player._head.y < 0 || _player._head.y >= _size.y) {
            status = DEAD_STATUS;
            return;
        }
        else if (_map[_player._head.x][_player._head.y] == FOOD) {
            auto it = find( _foods.begin(), _foods.end(), _player._head);
            if(it != _foods.end())
                _foods.erase(it);
            status = ENLARGE_STATUS;
            return;
        }
        status = STATIC_STATUS;
    }

    void renewMap() {
        if (status == DEAD_STATUS)  return ;
        for (int i = 0; i < _size.x; ++i)
            memset(_map[i], EMPTY, _size.y);
        auto it = _foods.begin();
        while (it != _foods.end()) {
            _map[it->x][it->y] = FOOD;
            *it++;
        }
        _map[_player._head.x][_player._head.y] = HEAD;
        for (int i = 0; i < _player._length; ++i) {
            _map[_player._body[i].x][_player._body[i].y] = BODY;
        }
    }

    void print() {
        for (int i = 0; i < _size.x; ++i) {
            for (int j = 0; j < _size.y; ++j)
                cout << _map[i][j];
            cout << endl;
        }
        cout << endl;
    }

    void move(direction dir) {
        _player.snakeMovement(dir);
        judge();
        if (status == ENLARGE_STATUS) {
            _player.snakeGrowth();
            status = STATIC_STATUS;
        }
        renewMap();
    }

    bool isGameOver() { return (status == DEAD_STATUS)? true : false; }

private:
    int status;
    char** _map;
    point _size;
    snake _player;
    std::list<point> _foods;
};

#endif