/* 
 * File:   stateIdentifier.cpp
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#include "stateIdentifier.h"
#include "../autoContainer.h"

//type = 1
stateIdentifier::stateIdentifier() {

}

/**
 * Wird vom Automaten aufgerufen über currentState->readChar(), d.h. dem Automat
 * ist nicht bewusst, welcher Zustand nun liest.
 * @param autom Pointer auf aufrufenden Automaten, dadurch wird immer der Weg 
 *                      zurück gefunden
 * @param c der einzulesende Char
 * 
 * @return den Pointer auf den aktualisierten autoContainer
 */
autoContainer* stateIdentifier::readChar(Automat* autom, const char* c) {
    autoContainer* current;
    
    // @if: Unterscheidung, ob der letzte autoContainer vorhanden ist
    if(autom->getCurrentContainer() == 0) {
        current = new autoContainer();
    } else {
        current = autom->getCurrentContainer();
    }
    
    //Übergänge einfügen
    
    return current;
}

void stateIdentifier::startState(State* states, int arrayLength) {
    if(!(this->started)) {
        this->arrayLength = arrayLength;
        this->states = new State[arrayLength];
        for(int i = 0; i < arrayLength; i++) {
            this->states[i] = states[i];
        }
        started = true;
    }
}