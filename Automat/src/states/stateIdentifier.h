/* 
 * File:   z1.h
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#ifndef STATEIDENTIFIER_H
#define	STATEIDENTIFIER_H

#include "../State.h"
#include "stateStart.h"

class stateIdentifier:public State {
public:
    autoContainer* readChar(Automat* autom, char c);
private:
    stateIdentifier();
};

#endif	/* STATEIDENTIFIER_H */
