/*
* File: stateIdentifier.h
* Author: Andy Perdana
*
* Created on 30. Oktober 2012, 11:36
*/

#ifndef STATEIDENTIFIER_H
#define STATEIDENTIFIER_H

#include "../State.h"
#include "stateStart.h"

class stateIdentifier:public State {
public:
    autoContainer* readChar(Automat* autom, autoContainer* con, char c);
    stateIdentifier();
private:

};

#endif /* STATEIDENTIFIER_H */
