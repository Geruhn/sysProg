/*
 * File: Automat.h
 * Created on: Oct 26, 2012
 * Author: Andy Perdana
 */

#ifndef Automat_H_
#define Automat_H_

#include "autoContainer.h"
//#include "../../Scanner/src/Scanner.h"


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

private:
    int STATES = 3;
    int currentState;
    autoContainer* currentContainer,* lastContainer;
//    Scanner scanner;

public:
    Automat();
    virtual ~Automat();

    void read(const char* c);
    void ungetChar(const char* c);
    void ungetChar(const char* chars, int arrayLength);

    autoContainer* getCurrentContainer();
    autoContainer* getLastContainer();
    enum states {
        start,
        identifier,
        digit,
        newLine,
        blank
    };
};

#endif /* Automat_H_ */
