/*
 * Symboltable.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "Hashtable.h"
#include"../../Automat/src/autoContainer.h"
#include "Pair.h"
#include "List.h"
#include "Element.h"

class Symboltable {
public:
	Symboltable();
	virtual ~Symboltable();
	autoContainer* insert(char* lex, autoContainer* autoc);
	autoContainer* get(char* lex, autoContainer* autoc);

	Hashtable<autoContainer*>* ht ;
};

#endif /* SYMBOLTABLE_H_ */
