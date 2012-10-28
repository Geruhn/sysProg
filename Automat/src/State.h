/* 
 * File:   State.h
 * Author: andy
 *
 * Created on 26. Oktober 2012, 14:00
 */

#ifndef STATE_H
#define	STATE_H
#include "../lib/autoContainer.h"

class State {
public:
    State* mkState();
    virtual ~State();
    virtual autoContainer* readChar(Automat* autom, char c) = 0;
private:
    State();

};

#endif	/* STATE_H */

