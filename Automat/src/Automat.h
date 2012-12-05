/*
 * File: Automat.h
 * Created on: Oct 26, 2012
 * Author: Andy Perdana
 */

#ifndef Automat_H_
#define Automat_H_

//#include "states/stateStart.h"
//#include "states/stateIdentifier.h"
//#include "states/stateDigit.h"

#include "autoContainer.h"
#include "StateInterface.h"
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
    StateInterface* currentState;
    StateInterface* states;
    autoContainer* currentContainer,* lastContainer;
    automatRegister* reg;
//    Scanner scanner;

public:
    Automat();
    virtual ~Automat();

    //void setTokenFound(int type);
    void setState(StateInterface* nextState);
    void read(const char* c);
    void ungetChar(const char* c);
    void ungetChar(const char* chars, int arrayLength);
    /**
     * Sollte es nicht geben, soll über die type-Variable des Containers heraus
     * gefunden werden. Also wird sie jetzt auskommentiert. - Andy
     * @return hasToken
     */
    //bool hasToken();

    autoContainer* getCurrentContainer();
    autoContainer* getLastContainer();
};

#endif /* Automat_H_ */
