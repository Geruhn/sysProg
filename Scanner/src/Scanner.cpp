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

		void* autoContainer; //zeiger auf den container, container enthält informationen über zeile,spalte identifier -max

		char zeichen;
		char stringInput[] = "../lib/inputFile.txt";
		char stringOutput[] = "../lib/outputFile.txt";

		Buffer* buffer = new Buffer(stringInput);
		Automat* automat = new Automat();
		Symboltable* symbolTable = new Symboltable();
		Hashtable* hashTable = new Hashtable(10000);


		while(!buffer->isEOF){ //holt die Zeichen aus dem Buffer und gibt sie dem automaten, anschließend wirds in die symboltabelle gepackt -max

			autoContainer = automat->read(buffer->getChar()); //autocontainer enthält informationen über die zeile, spalte, identifier -max
			//symbloTable->add(autoContainer);
			hashTable->

		}
}


