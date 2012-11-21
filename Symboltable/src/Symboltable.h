/*
 * Symboltable.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "Hashtable.h"

class Symboltable {
public:
	Symboltable();
	virtual ~Symboltable();
	void insert(char* lex, int type);
};

#endif /* SYMBOLTABLE_H_ */
