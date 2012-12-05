/*
 * Token.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "Token.h"

Token::Token(int type, int line, int col, autoContainer* infoContainer) {
	this->type = type;
	this-> col = col;
	this->line = line;
	this->infoContainer = infoContainer;
}

Token::~Token() {
	delete this->infoContainer;
}

int Token::getCol(){
	return this->col;
}

int Token::getLine(){
	return this->line;
}

autoContainer* Token::getInfoContainer(){
	return this->infoContainer;
}
