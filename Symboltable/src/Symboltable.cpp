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

	return ht->insert(lex,autoc->length);

}

autoContainer* Symboltable::get(char* lex, autoContainer* type) {

	ht->get(lex, type);

}
