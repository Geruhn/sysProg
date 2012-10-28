#include "Scanner.h"


int main(int argc, char **argv) {

	//Scanner* scanner;

	//scanner = new Scanner();

	char zeichen;
	char stringInput[] = "../lib/myFile.txt";
	char stringOutput[] = "../lib/writeFile.txt";

	Buffer* buffer = new Buffer(stringInput);
	Automat* automat = new Automat();

	while(!buffer->isEOF){
		zeichen = buffer->getChar();


	}

}

