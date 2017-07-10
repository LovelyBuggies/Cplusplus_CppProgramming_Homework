//
// State.cpp
// C++
//
// Created by Nino on Apr.29 2017.
// Copyright © Nino 2017. All rights reserved.
//

#include "State.hpp"
#include "Parser.hpp"
#define spc ' '
#define rtn '\r'
#define ent '\n'



State* DataState::_instance = NULL;
State* DataState::getInstance() {
	if(!_instance)
        _instance = new DataState();
    return _instance;
}
void DataState::destroyInstance() {
	if(_instance)
		delete _instance;
	_instance = NULL;
}
void DataState::handleOneChar(Parser* parser, char ch) {
    if(ch == spc && _cache.length() == 0) return;
    if(ch == rtn || ch == ent) return;
    Parser* p = parser->getInstance();
    if(ch != '<') {
    	_cache = _cache + ch;
    	return;
    }
    emit(p->getBulider());
    p->setState(TagNameState::getInstance());
}
void DataState::emit(Bulider* dest) {
	Token temp;
	temp.type = "DATA";
	temp.content = _cache;
	dest->handleOneToken(temp);
	_cache.clear();
}







State* TagNameState::_instance = NULL;
State* TagNameState::getInstance() {
	if(!_instance)
        _instance = new TagNameState();
    return _instance;
}
void TagNameState::destroyInstance() {
	if(_instance)
		delete _instance;
	_instance = NULL;
}
void TagNameState::handleOneChar(Parser* parser, char ch) {
	if(ch == spc && _cache.length() == 0) return;
  if(ch == rtn || ch == ent) return;
	Parser* p = parser->getInstance();
    if(ch != '>') {    
    	_cache = _cache + ch;
        return;
    }
    emit(p->getBulider());
    p->setState(DataState::getInstance());
}
void TagNameState::emit(Bulider* dest) {
  if(_cache.length()==0) return;
	Token temp;
	if(_cache[0] == '/')
		temp.type = "CLOSE_TAG";
	else 
		temp.type = "OPEN_TAG";
	temp.content = _cache;
	dest->handleOneToken(temp);
	_cache.clear();
}