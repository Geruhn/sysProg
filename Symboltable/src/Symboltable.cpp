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
	ht = new Hashtable<autoContainer*>(1000);

}

Symboltable::~Symboltable() {
	// TODO Auto-generated destructor stub
}

autoContainer* Symboltable::insert(char* lex, autoContainer* autoc) {

	autoContainer* returnValue;
	bool putReturn;
	putReturn = ht->put(lex, autoc);
	if(putReturn){
		returnValue = ht->get(lex);
	}
	return returnValue;

}

autoContainer* Symboltable::get(char* lex, autoContainer* type) {

	return ht->get(lex);
}
