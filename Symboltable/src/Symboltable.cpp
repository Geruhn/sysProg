/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

/*
 * Symboltable fügt Lexem und Type in Hashtable ein und gibt einen Pointer auf die Position des Lexems zurück
 */

#include "Symboltable.h"

Symboltable::Symboltable() {
	// TODO Auto-generated constructor stub

}

Symboltable::~Symboltable() {
	// TODO Auto-generated destructor stub
}

char* Symboltable::insert(char* lex, int type) {

	Hashtable<int> hashtable = new Hashtable(1000);
	char* returnValuePointer;

	//Länge aus Infocontainer rausholen und insert mitgeben
	returnValuePointer = hashtable.insert(lex,type,2);

	//Pointer auf Position des gespeicherten Lexems und Types
	return returnValuePointer;

}
