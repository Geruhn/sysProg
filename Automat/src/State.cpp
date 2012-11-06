/* 
 * File:   State.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:00
 */

#include "State.h"

State::State() {
    
}

void State::startState(State* states, int arrayLength) {
    this->arrayLength = arrayLength;
    this->states = new State[arrayLength];
    for(int i = 0; i < arrayLength; i++) {
        this->states[i] = states[i];
    }
}

State::~State() {
}
