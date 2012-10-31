/*
 * Automat.h
 *
 *  Created on: Oct 26, 2012
 *      Author: Andy Perdana
 */

#ifndef Automat_H_
#define Automat_H_
#include "State.h"
#include "states/z0.h"
#include "states/z1.h"

class Automat {

private:
    int statesLength;
    int line, col,length;
    State *current;
    State* states;

public:

    void increaseLine();
    void increaseCol();
    void increaseLength();
    void decreaseLine();
    void decreaseCol();
    void decreaseLength();
    void resetCol();
    void resetLength();

	Automat();
	virtual ~Automat();
    void read(char c);
    void setState(State *nextState);
    int findState(State *toBeFound);

};

#endif /* Automat_H_ */
