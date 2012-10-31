/* 
 * File:   z1.h
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#ifndef Z1_H
#define	Z1_H

#include "../State.h"
#include "z0.h"

class z1:public State {
public:
    State* mkState();
    autoContainer* readChar(Automat* autom, char c);
private:
    z1();
    static State *theStateZ1;
};

#endif	/* Z1_H */
