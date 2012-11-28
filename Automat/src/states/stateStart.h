/*
* File: stateStart.h
* Author: Andy Perdana
*
* Created on 26. Oktober 2012, 14:15
*/

#ifndef STATESTART_H
#define STATESTART_H

#include "stateIdentifier.h"

class stateStart:public State {
public:
    stateStart();
    autoContainer* readChar(Automat* autom, autoContainer* con, char c);
private:
    autoContainer current;
};

#endif /* STATESTART_H*/
