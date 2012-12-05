/* 
 * File:   StateInterface.h
 * Author: andy
 *
 * Created on December 4, 2012, 11:45 PM
 */

#ifndef STATEINTERFACE_H
#define	STATEINTERFACE_H

#include "autoContainer.h"
#include "automatRegister.h"

class StateInterface {
public:
//    virtual StateInterface() = 0;
//    virtual StateInterface(const StateInterface& orig) = 0;
    virtual ~StateInterface();
    virtual void startState(StateInterface* states, int arrayLength) = 0;
    virtual autoContainer* readChar(const char* c) = 0;
private:
//    StateInterface* states;
//    int arrayLength;
//    bool started;
//    automatRegister reg;
};

#endif	/* STATEINTERFACE_H */

