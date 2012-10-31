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
    autoContainer* readChar(Automat* autom, char c);
private:  
    static State* mkState();
    z0();
};

#endif	/* Z0_H */
