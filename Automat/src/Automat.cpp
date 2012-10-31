/* 
 * File:   Automat.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:00
 */

//#include "State.h"
#include "Automat.h"
#include "states/z0.h"


Automat::Automat() {
    this->states = new State[1];
    this->current = 0;
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}

Automat::setState(State* nextState) {
    current = findState(nextState);
    if (current == -1) {
        if (statesLength == 0) {
            states[0] = new z0();
        } else {
            states[1] = new z1();
        }
    }
}       

Automat::findState(State* toBeFound) {
    int found = -1;
    for (int i = 0; i < statesLength; i++) {
        if ((states + i) == toBeFound) {
            found = i;
        }
    }
}