/* 
 * File:   stateStart.h
 * Author: Andy Perdana
 *
 * Created on 26. Oktober 2012, 14:15
 */

#ifndef STATESTART_H
#define	STATESTART_H

#include "../autoContainer.h"
#include "../Automat.h"
#include "../StateInterface.h"

class stateStart:public StateInterface {
public:
    stateStart();
    void startState(StateInterface* states, int arrayLength);
    autoContainer* readChar(const char* c);
private:
    StateInterface* states;
    int arrayLength;
    bool started;
    automatRegister* autom;    
};

#endif	/* STATESTART_H*/
