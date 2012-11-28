/*
* File: Automat.cpp
* Author: Andy Perdana
*
* Created on 26. Oktober 2012, 14:00
*/

#include "Automat.h"

/*
* Current soll Pointer sein. Zustand legt neuen Zustand in demensprechenden Übergang fest und gibt dem Automaten per setState()
* einen Pointer auf den neuen Zustand der in Current gespeichert wird zum weiterarbeiten.
*/
/**
* In STATES steht die aktuelle Anzahl aller Zustände drin, sie muss vor dem
* make-Befehl aktualisiert werden, falls sich die Anzahl der möglichen
* Zustände ändert. Und ins Array eingespeichert werden.
*/
Automat::Automat() {
    //isToken = false;

    this->states = new State[STATES];
    this->states[0] = new stateStart();
    this->states[1] = new stateIdentifier();
    //this->states[2] = new stateDigit();

    this->currentState = this->states;
    
    for(int i = 0; i < this->STATES; i++) {
        (states+i)->startState(states, STATES);
    }
}

Automat::~Automat() {
// TODO Auto-generated destructor stub
}
/*
* Funktion zum setzen des aktuellen Zustandes.
* @param nextState Pointer to the next State.
*/
void Automat::setState(char* nextState) {

	switch(nextState) {

	case "Identifier": currentState = states[1];
	break;
	//case "Digit": currentState = state[2];
	break;
	default: currentState = states[0];
	break;
	}
}

/*
* Reads a character and return an autoContainer with information about the Token.
* @param c Character that the machine has to read.
*/
void Automat::read(char c){
	currentContainer = currentState->readChar(this, currentContainer, c);
}

/*
* Return a pointer to the autoContainer of the actuel found Token. If actually no Token was found,
* the function returns an Null-Pointer.
* @return autoContainer Pointer to the autoContainer of the Token.
*/
autoContainer* Automat::getCurrentContainer(){
	if(isToken){
		lastContainer = currentContainer;
		isToken = false;
		currentContainer = 0;
		return lastContainer;
	}
	return 0;
	}

autoContainer* Automat::getLastContainer(){
		return lastContainer;
}
