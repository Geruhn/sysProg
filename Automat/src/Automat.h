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
    State* current;
public:
	Automat();
	virtual ~Automat();
        void read(char c) {
            current->readChar(this, c);
        };
        
        void setState(State* nextState) {
            current = nextState;                    
        };
};

#endif /* Automat_H_ */
