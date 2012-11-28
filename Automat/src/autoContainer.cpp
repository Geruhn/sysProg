/*
* File: autoContainer.cpp
* Author: Andy Perdana
*
* Created on 28. Oktober 2012, 14:08
*/

#include "autoContainer.h"
/**
 * Einzige Verwendung, wenn es noch keinen Container gab.
 */

autoContainer::autoContainer(){
    line = 1;
    type = length = col = 0;
}

autoContainer::autoContainer(autoContainer* old) {
    this->line = old->line;
    this->col = old->col;
    this->type = old->type;
    this->length = old->length;
    this->name = new char[this->length + 1];
    for (int i = 0; i < this->length; i++) {
        this->(name + i) = old->(name + i);
    }
    this->(name + length) = '\0';
}
/*
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
*/
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

/*
char* autoContainer::getName(){
	return name;
}
*/

void autoContainer::increaseCol(){
	col++;
	length++;
}

void autoContainer::increaseLine(){
	col = 1;
	line++;
	length = 0;
}

/**
 * Setzt die Typ-Variante um, so dass feststellbar ist, welches Lexem in diesem
 * Container abgespeichert ist.
 * @param type s. autoContainer.h für Aufschlüsselung aller möglichen Typen
 */
void autoContainer::setType(int type){
this->type = type;
}

