/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "Buffer.h"
#include "Automat.h"
#include "Token.h"
#include "Symboltable.h"
class Scanner {

private:
	Buffer* inBuffer;
	Buffer* outBuffer;
	Automat* automat;
	Symboltable* symbolTable;
	Token* currentToken;

	bool hasToken;

	void createToken();

public:
	Scanner();
	virtual ~Scanner();
	void ungetChar();
	Token nextToken();
};

#endif /* SCANNER_H_ */
