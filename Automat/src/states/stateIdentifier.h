/* 
 * File:   stateIdentifier.h
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#ifndef STATEIDENTIFIER_H
#define	STATEIDENTIFIER_H

#include "../autoContainer.h"
#include "../AutomatInterface.h"
#include "../State.h"
//#include "stateStart.h"

class stateIdentifier:public State {
public:
    stateIdentifier();
    void startState(State* states, int arrayLength);
    autoContainer* readChar(AutomatInterface* autom, const char* c);
private:
    State* states;
    int arrayLength;
    bool started;
};

#endif	/* STATEIDENTIFIER_H */
