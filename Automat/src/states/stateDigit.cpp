/*
 * File:   stateDigit.cpp
 * Author: Andy Perdana
 * 
 * Created on 19. November 2012, 11:36
 */

#include "stateDigit.h"
#include "../autoContainer.h"
#include "../AutomatInterface.h"

//type = 2
stateDigit::stateDigit() {

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
autoContainer* stateDigit::readChar(const char* c) {
    autoContainer* current;
    
    // @if: Unterscheidung, ob der letzte autoContainer vorhanden ist
    if(this->autom->getCurrentContainer() == 0) {
        current = new autoContainer();
    } else {
        current = this->autom->getCurrentContainer();
    }

    //Übergänge einfügen
    
    return current;
}

void stateDigit::startState(AutomatInterface* autom, State* states, int arrayLength) {
    this->autom = autom;
    if(!(this->started)) {
        this->arrayLength = arrayLength;
        this->states = new State[arrayLength];
        for(int i = 0; i < arrayLength; i++) {
            this->states[i] = states[i];
        }
        started = true;
    }
}
