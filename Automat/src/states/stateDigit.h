/* 
 * File:   stateIdentifier.h
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#ifndef STATEDIGIT_H
#define	STATEDIGIT_H

#include "../autoContainer.h"
#include "../Automat.h"
#include "../StateInterface.h"

class stateDigit:public StateInterface {
public:
    stateDigit();
    void startState(StateInterface* states, int arrayLength);
    autoContainer* readChar(const char* c);
private:
    StateInterface* states;
    int arrayLength;
    bool started;
    automatRegister* autom;
};

#endif	/* STATEIDENTIFIER_H */
