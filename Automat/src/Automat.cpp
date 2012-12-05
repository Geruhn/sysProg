/*
* File: Automat.cpp
* Author: Andy Perdana
*
* Created on 26. Oktober 2012, 14:00
*/

#include "Automat.h"
/**
* In STATES steht die aktuelle Anzahl aller Zustände drin, sie muss vor dem
* make-Befehl aktualisiert werden, falls sich die Anzahl der möglichen
* Zustände ändert. Und ins Array eingespeichert werden.
*/
Automat::Automat() {
    currentState = 0;
}

Automat::~Automat() {
// TODO Auto-generated destructor stub
}

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
}

/** 
 * 
 * @return Pointer to the current autoContainer
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
