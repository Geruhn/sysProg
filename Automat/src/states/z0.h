/* 
 * File:   z0.h
 * Author: Andy Perdana
 *
 * Created on 26. Oktober 2012, 14:15
 */

#ifndef Z0_H
#define	Z0_H

#include "../State.h"
#include "z1.h"

class z0:public State {
public:

    State* mkState();
    autoContainer* readChar(Automat* autom, char c);

private:
    z0();
    static State *theStateZ0;
    State z1;
};

#endif	/* Z0_H */
