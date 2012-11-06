/* 
 * File:   Automat.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:00
 */

#include "State.h"
#include "states/stateStart.h"
#include "states/stateIdentifier.h"
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
    this->states = new State[this->STATES];
    (states + 0) = new stateStart();
    (states + 1) = new stateIdentifier();
    
    this->current = this->states;
    
    for(int i = 0; i < STATES; i++) {
        this->states[i].startState();
    }
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}
/*
 * Funktion zum setzen des aktuellen Zustandes.
 * @param *nextState Pointer auf den aktuellen Zustand.
 */
void Automat::setState(State *nextState) {
    this->current = nextState;    
}

void Automat::read(char c){
	current->readChar(this, c);
}
/*
void Automat::increaseLine(){
	line++;
}
void Automat::increaseCol(){
	col++;
}

void Automat::increaseLength(){
	length++;
}
void Automat::decreaseLine(){
	line++;
}
void Automat::decreaseCol(){
	col++;
}

void Automat::decreaseLength(){
	length++;
}

void Automat::resetCol(){
	col=0;
}

void Automat::resetLength(){
	length=0;
}
*/
