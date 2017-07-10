//
// Bulider.cpp
// C++
//
// Created by Nino on Apr.29 2017.
// Copyright © Nino 2017. All rights reserved.
//

#include "Bulider.hpp"
#include <iostream>
using namespace std;


Bulider* Bulider::_instance = NULL;
Bulider* Bulider::getInstance() {
	if(!_instance)
        _instance = new Bulider();
    return _instance;
}
void Bulider::destroyInstance() {
	if(_instance)
		delete _instance;
	_instance = NULL;
}
void Bulider::handleOneToken(Token token) {
	if(_stack.size() == 0 && token.type == "CLOSE_TAG") {
		_error = true;
		return;
	}
	if(token.type == "DATA") {
		token.depth = _stack.size();
		_tokens.push_back(token);
	}
	else if(token.type == "OPEN_TAG") {
		token.depth = _stack.size();
		_stack.push(token);
		_tokens.push_back(token);
	}
	else if(token.type == "CLOSE_TAG") {
		string cmp = "/" + _stack.top().content;
		if(token.content == cmp) {
			_stack.pop();
		}
		else 
			_error = true;
	}
}
void Bulider::display() {
	if(_error || _stack.size() != 0)
		cout << "INVALID INPUT" << endl;
	else
		for(std::vector<Token>::iterator itr = _tokens.begin();
			itr != _tokens.end(); itr++) 
			if(itr->content.length()) {
				while(itr->depth--)
					cout << "  ";
            if(itr->type == "OPEN_TAG" || itr->type == "CLOSE_TAG") 
            	cout << itr->content << ":";
            else
            	cout << itr->content;
            cout << endl;

		}
	_tokens.clear();
	for(int i = 0; i < _stack.size(); i++)
		_stack.pop();
}