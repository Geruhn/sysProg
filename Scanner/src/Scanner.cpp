/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "Scanner.h"

Scanner::Scanner() {

	char stringInput[] = "../readFile.txt";
	char stringOutput[] = "../writeFile.txt";

	automat = new Automat();
	inBuffer = new Buffer(stringInput);
	outBuffer = new Buffer(stringOutput);
}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
	delete automat;
	delete inBuffer;
	delete outBuffer;
	delete symbolTable;
}
//Methode wird vom Automat nur aufgerufen, wenn ein Token abgeschlossen wurde.
//Deshalb wird das Token einfach in der ungetChar()- Methode erstellt
void Scanner::ungetChar(){
	inBuffer->ungetChar();
	createToken();
}

Token Scanner::nextToken(){
	while(inBuffer->hasNext() & hasToken ){
		automat->read(inBuffer->getChar());
	}
	return currentToken();
}

void Scanner::createToken(){
	currentToken = new Token(this->automat->getCurrentContainer()->getType(),
							 this->automat->getCurrentContainer()->getLine(),
							 this->automat->getCurrentContainer()->getCol(),
							 this->symbolTable->insert(
									 this->automat->getCurrentContainer()->getName(),
									 this->automat->getCurrentContainer()));
	hasToken = true;
}
