/* 
 * File:   stateStart.h
 * Author: Andy Perdana
 *
 * Created on 26. Oktober 2012, 14:15
 */

#ifndef STATESTART_H
#define	STATESTART_H

#include "../autoContainer.h"
#include "../AutomatInterface.h"
#include "../State.h"
//#include "stateIdentifier.h"

class stateStart:public State {
public:
    stateStart();
    void startState(State* states, int arrayLength);
    autoContainer* readChar(AutomatInterface* autom, const char* c);
private:  
    //autoContainer current;
    State* states;
    int arrayLength;
    bool started;
    
};

#endif	/* STATESTART_H*/
