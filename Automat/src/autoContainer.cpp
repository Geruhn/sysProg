/*
 * File:   autoContainer.cpp
 * Author: Andy Perdana
 *
 * Created on 28. Oktober 2012, 14:08
 */

#include "autoContainer.h"
/**
 * Gibt's für den Standardkonstruktor irgendeine Verwendung? Der muss ja
 * eigentlich immer sofort mit Daten bzgl Typ, c etc. gefüttert werden, oder? 
 * So lange würde ich das auskommentiert lassen, damit's keiner nutzt.
 * - Andy
 */
/*
autoContainer::autoContainer(){
	line = 1;
	type = length = col = 0;
}*/

autoContainer::autoContainer(int line, int col, int length, char c, int type){
    this->line = line;
    this->col = col;
    this->length = length;
    this->name = new char[2];
    this->name[0] = c;
    this->name[1] = '\0';
    if(type>0 || type<4) {
        this->type = type;
    } else {
        this->type = 0;
    }
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
	length = 0;
}

void autoContainer::setType(int type){
	this->type = type;
}

