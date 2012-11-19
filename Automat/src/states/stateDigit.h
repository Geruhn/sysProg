/* 
 * File:   stateIdentifier.h
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#ifndef STATEDIGIT_H
#define	STATEDIGIT_H

#include "../State.h"
//#include "stateStart.h"

class stateDigit:public State {
public:
    stateDigit();
    void startState(State* states, int arrayLength);
    autoContainer* readChar(Automat* autom, const char* c);
private:
    State* states;
    int arrayLength;
    bool started;
};

#endif	/* STATEIDENTIFIER_H */
