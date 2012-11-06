/*
 * Automat.h
 *
 *  Created on: Oct 26, 2012
 *      Author: Andy Perdana
 */

#ifndef Automat_H_
#define Automat_H_
//#include "State.h"
//#include "states/stateStart.h"
//#include "states/stateIdentifier.h"
/**
 * The state machine class "Automat" starts with creating every state that is
 * needed to identify every possible token and errors. After that all the 
 * information about line, column and the length of the current word or symbol 
 * will be saved in the autoContainer object created by the current state, it 
 * keeps updating the container until it discovers a new word, it then creates
 * a new container, the old one must be destroyed by the last one using it, it's
 * possible, that the container will be a part of the info in the symbol table.
 * - Andy
 */
class Automat {
    //friend class State;

private:
    //int line, col,length;
    const static int STATES = 2;
    State *current;
    State *states;
public:/*
    void increaseLine();
    void increaseCol();
    void increaseLength();
    void decreaseLine();
    void decreaseCol();
    void decreaseLength();
    void resetCol();
    void resetLength();*/

    Automat();
    virtual ~Automat();
    void setState(State* nextState);
    void read(char c);
};

#endif /* Automat_H_ */
