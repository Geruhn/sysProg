/*
 * Automat.h
 *
 *  Created on: Oct 26, 2012
 *      Author: Andy Perdana
 */

#ifndef Automat_H_
#define Automat_H_
#include "State.h"

class Automat {
private:
    int current, statesLength;
    State* states;
public:
	Automat();
	virtual ~Automat();
        void read(char c) {
            (states + current)->readChar(this, c);
        };
        
        void setState(State* nextState);
        int findState(State* toBeFound);
};

#endif /* Automat_H_ */
