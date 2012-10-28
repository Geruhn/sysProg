/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "Scanner.h"

Scanner::Scanner() {
	// TODO Auto-generated constructor stub

}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

void Scanner::runScanner(){

	void* autoContainer; //zeiger
		char zeichen;
		char stringInput[] = "../lib/inputFile.txt";
		char stringOutput[] = "../lib/outputFile.txt";

		Buffer* buffer = new Buffer(stringInput);
		Automat* automat = new Automat();

		while(!buffer->isEOF){ //holt die Zeichen aus dem Buffer und gibt sie dem automaten -max
			zeichen = buffer->getChar();
			autoContainer = automat->readChar(zeichen);

		}
}


