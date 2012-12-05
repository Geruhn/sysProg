/* 
 * File:   Automat.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:00
 */

#include "Automat.h"
//#include "StateInterface.h"
/*
 * Current soll Pointer sein. Zustand legt neuen Zustand in demensprechenden Übergang fest und gibt dem Automaten per setStateInterface()
 * einen Pointer auf den neuen Zustand der in Current gespeichert wird zum weiterarbeiten.
 */
/**
 * In STATES steht die aktuelle Anzahl aller Zustände drin, sie muss vor dem
 * make-Befehl aktualisiert werden, falls sich die Anzahl der möglichen 
 * Zustände ändert. Und ins Array eingespeichert werden.
 */
Automat::Automat() {
    currentState = 0;
    //isToken = false;

//    this->reg = new automatRegister(this);
//    this->states = new StateInterface[STATES];
//    this->states[0] = (StateInterface*) new stateStart();
//    this->states[1] = (StateInterface*) new stateIdentifier();
//    this->states[2] = (StateInterface*) new stateDigit();
//
//    this->currentState = (StateInterface*) this->states;
//    
//    for(int i = 0; i < this->STATES; i++) {
//        (states+i)->startState(states, STATES);
//    }
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}
/*
 * Funktion zum setzen des aktuellen Zustandes.
 * FYI: Erst ab Java7 ist es möglich switch-case mit einem String zu machen.
 * @param nextState Pointer to the next State.
 */
//void Automat::setState(StateInterface* nextState) {
//    this->currentState = nextState;
//}

/*
 * Reads a character and return an autoContainer with information about the Token.
 * @param c Character that the machine has to read.
 */
void Automat::read(const char* c){    
    switch(states[currentState]) {
        case start:
            break;
        case identifier:
            break;
        case digit:
            break;
        case newLine:
            break;
        case blank:
            break;
        default:
            break;
            
    }
//    this->currentContainer = this->currentState->readChar(c);
    
}

void Automat::ungetChar(const char* c) {
    this->ungetChar(c, 1);
}
void Automat::ungetChar(const char* chars, int arrayLength) {
    for(int i = 0; i < arrayLength; i++) {
        //this->scanner->ungetChar((chars + i)*);
    }
}

/*
 * Function signals if a Token was found.
 * @return bool True if a new Token was found. False if there is no new Token.
 */
/*
bool Automat::hasToken(){
	return isToken;
}
 */

/*
 * Function get called if a Token is found/finished.
 * @param type Type of the found Token.
 */
/* Begründung s. hasToken.
void Automat::setTokenFound(int type){
	isToken = true;
	currentContainer->setType(type);
}
*/

/** 
 * 
 * @return Pointer to the current autoContainer
 */
autoContainer* Automat::getCurrentContainer(){
    return currentContainer;
}

autoContainer* Automat::getLastContainer(){
    return lastContainer;
}
