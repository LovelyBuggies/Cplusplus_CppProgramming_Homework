//
// Parser.cpp
// C++
//
// Created by Nino on Apr.29 2017.
// Copyright © Nino 2017. All rights reserved.
//

#include "Parser.hpp"

/* 
   properties
   static Parser* _instance;
   std::string _str;
   State* _state;
   Bulider* _bulider;
*/

Parser* Parser::_instance = NULL;
Parser* Parser::getInstance() {
	if(!_instance)
        _instance = new Parser();
    return _instance;
}
void Parser::destroyInstance() {
	if(_instance)
		delete _instance;
	_instance = NULL;
}
void Parser::consumeOneChar(char ch) {
    _state->handleOneChar(this, ch);
}