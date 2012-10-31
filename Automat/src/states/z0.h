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
<<<<<<< HEAD
    z0();
    State* mkState();
    autoContainer* readChar(Automat* autom, char c);
private:
=======
>>>>>>> maxbauer

    static State* mkState();
    autoContainer* readChar(Automat* autom, char c);

private:
    z0();
    static State *Startzustand;
    State z1;
};

<<<<<<< HEAD
#endif	/* Z0_H */
=======
#endif	/* Z0_H */
>>>>>>> maxbauer
