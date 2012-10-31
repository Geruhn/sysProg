/* 
 * File:   Automat.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:00
 */

//#include "State.h"
#include "Automat.h"



Automat::Automat() {
    this->states = new State[1];
    this->current = 0;
    statesLength=10;
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}

void Automat::setState(State* nextState) {
    current = findState(nextState);
    if (current == -1) {
        if (statesLength == 0) {
            states[0] = new z0();
        } else {
            states[1] = new z1();
        }
    }
}       

int Automat::findState(State* toBeFound) {
    int found = -1;
    for (int i = 0; i < statesLength; i++) {
        if ((states + i) == toBeFound) {
            found = i;
        }
    }
    return found;
}

void Automat::increaseLine(){
	line++;
}
void Automat::increaseCol(){
	col++;
}

void Automat::increaseLength(){
	length++;
}
void Automat::decreaseLine(){
	line++;
}
void Automat::decreaseCol(){
	col++;
}

void Automat::decreaseLength(){
	length++;
}

void Automat::resetCol(){
	col=0;
}

void Automat::resetLength(){
	length=0;
}
