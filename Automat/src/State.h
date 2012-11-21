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
#include "Automat.h"

class State {

public:
    State();
    /**
     * Eigene Umsetzung der startState in jedem Zustand, dann werden nur die 
     * Pointer auf relevante Zustände abgespeichert.
     * 
     * @param states alle Zustände die der Automat kennt in einer fest 
     *                  definierten Reihenfolge, wird diese im Automat geändert
     *                  muss die Zuordnung in den betroffenen Zuständen 
     *                  angepasst werden.
     * @param arrayLength Die Menge aller Zustände, ist wichtig um nicht in 
     *                          einen OutOfArray-Fehler zu produzieren.
     */
    virtual void startState(State* states, int arrayLength) = 0;
    virtual ~State();
    /**
     * Frägt vorm Einlesen eines chars, ob der Zustand schon startbereit ist 
     * (started == true), 
     * @param autom Der zugehörige Automat, darüber kann dann die 
     *                  getCurrentContainer() aufgerufen werden und es wird 
     *                  immer der aktuellste Container
     * @param c Der einzulesende char.
     * @return Info-Container, s. autoContainer-Doku
     */
    virtual autoContainer* readChar(Automat* autom, char c) = 0;


private:
    //virtual State* states;
    //virtual int arrayLength;
    /**
     * Gibt an, ob der Zustand schon startbereit ist, ist dies nicht so, soll
     * die readChar-Funktion einen Fehler werfen.
     */
    //virtual bool started;
};

#endif	/* STATE_H */

