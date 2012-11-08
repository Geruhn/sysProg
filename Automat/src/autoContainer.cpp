/*
 * File:   autoContainer.cpp
 * Author: Andy Perdana
 *
 * Created on 28. Oktober 2012, 14:08
 */

#include "autoContainer.h"

autoContainer::autoContainer(){
	line = 1;
	type = length = col = 0;
}

autoContainer::autoContainer(int line, int col){
	this->line = line;
	this->col = col;
	length = 0;
	type = 0;
}

int autoContainer::getCol(){
	return col;
}

int autoContainer::getLine(){
	return line;
}

int autoContainer::getLength(){
	return length;
}

int autoContainer::getType(){
	return type;
}

char* autoContainer::getName(){
	return name;
}

void autoContainer::increaseCol(){
	col++;
	length++;
}

void autoContainer::increaseLine(){
	col = 1;
	line++;
	length++;
}

void autoContainer::setType(int type){
	this->type = type;
}

