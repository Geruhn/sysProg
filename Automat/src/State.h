/* 
 * File:   State.h
 * Author: Andy Perdana
 *
 * Created on 26. Oktober 2012, 14:00
 */

/**
 * Der Plan ist, dass alle Zustände alle anderen kennen, nach dem alle Zustände
 * erstellt wurden, wird die Funktion startState() aufgerufen und das Array mit 
 * allen Zuständen übergeben. Dann wird bei setState, immer der Pointer aus dem 
 * Array an den Automaten übergeben und alle sind glücklich.
 */

#ifndef STATE_H
#define	STATE_H
#include "autoContainer.h"
class Automat;

class State {
public:
    State();
    void startState(State* states, int arrayLength);
    //virtual State* mkState();
    virtual ~State();
    /**
     * Frägt vorm Einlesen eines chars, ob der Zustand schon startbereit ist 
     * (started == true), 
     * @param autom Der zugehörige Automat
     * @param c Der einzulesende char.
     * @return Info-Container, s. autoContainer-Doku
     */
    virtual autoContainer* readChar(Automat* autom, char c);


private:
    State* states;
    int arrayLength;
    /**
     * Gibt an, ob der Zustand schon startbereit ist, ist dies nicht so, soll
     * die readChar-Funktion einen Fehler werfen.
     */
    bool started;
};

#endif	/* STATE_H */

