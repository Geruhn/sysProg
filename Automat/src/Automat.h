/*
 * Automat.h
 *
 *  Created on: Oct 26, 2012
 *      Author: Andy Perdana
 */

#ifndef Automat_H_
#define Automat_H_



class Automat {
private:
    State* current;
public:
	Automat();
	virtual ~Automat();
        read(char c) {
            current->readChar(this, c);
        };
        
        setState(State* nextState) {
            current = nextState;                    
        };
};

#endif /* Automat_H_ */
