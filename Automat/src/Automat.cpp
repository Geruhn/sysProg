/* 
 * File:   Automat.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:00
 */

#include "Automat.h"

/*
 * Current soll Pointer sein. Zustand legt neuen Zustand in demensprechenden Übergang fest und gibt dem Automaten per setState()
 * einen Pointer auf den neuen Zustand der in Current gespeichert wird zum weiterarbeiten.
 */

Automat::Automat() {
	isToken = false;

    this->states = new State[STATES];
    this->states[0] = new stateStart();
    this->states[1] = new stateIdentifier();
    
    this->currentState = this->states;
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}
/*
 * Funktion zum setzen des aktuellen Zustandes.
 * @param nextState Pointer to the next State.
 */
void Automat::setState(char* nextState) {

	switch(nextState)
	{
	 case "Identifier": currentState = states[1];
	 	 	 	 	 	 break;

	 default: currentState = states[0];
	 	 	  break;

	}
}

/*
 * Reads a character and return an autoContainer with information about the Token.
 * @param c Character that the machine has to read.
 * @return autoContainer Contents information about the Token.
 */
void Automat::read(char c){
	currentContainer = currentState->readChar(this, currentContainer, c);
}

/*
 * Function signals if a Token was found.
 * @return bool True if a new Token was found. False if there is no new Token.
 */
bool Automat::hasToken(){
	return isToken;
}

/*
 * Function get called if a Token is found/finished.
 * @param type Type of the found Token.
 */
void Automat::setTokenFound(int type){
	isToken = true;
	currentContainer->setType(type);
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
