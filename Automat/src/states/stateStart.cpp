/* 
 * File:   stateStart.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:15
 */


//#include "../State.h"
#include "stateStart.h"
#include "../autoContainer.h"
#include "src/AutomatInterface.h"

//type = 0
stateStart::stateStart() {

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
autoContainer* stateStart::readChar(const char* c) {
    autoContainer* current;
    
    // @if: Unterscheidung, ob der letzte autoContainer vorhanden ist
    if(this->autom->getCurrentContainer() == 0) {
        current = new autoContainer();
    } else {
        current = this->autom->getCurrentContainer();
    }
    
    //@if: Unterscheidung, welcher Übergang jetzt genommen wird.
    if( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ){
        current->increaseCol();
        current->setType(1);
        this->autom->setState(states+1); //Identifier
    } else if( c == '\n'){ //Für Zeilenumbrüche
        if(current->getType() == 0) {
            current->increaseLine();
            current->setType(4);                  //new Line
        } else {
            this->autom->ungetChar(c);
        }
    } else if(c == 32) { //Für Leerzeichen
        if(current->getType() == 0) {
            current->increaseCol();
            current->setType(5);
        } else {
            this->autom->ungetChar(c);
        }
    } else if( c >= '0' && c <= '9'){
    	current->increaseCol();
        current->setType(2);
    	this->autom->setState(states+2);
    }
    
    return current;
}


void stateStart::startState(AutomatInterface* autom, State* states, int arrayLength) {
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