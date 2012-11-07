#include "Automat.h"
#include "../Buffer/src/Buffer.h"
#include "autoContainer.h"

int main (int argc, char* argv[]){
	Automat* automat = new Automat();
	Buffer* inBuffer = new Buffer("../readFile.txt");
	Buffer* outBuffer = new Buffer("../wirteFile.txt");
	autoContainer* con = new autoContainer();

	while(inBuffer->hasNext()){
		if(automat->hasToken()){
			con = automat->getCurrentContainer();
			for(int i = 0; i < con->getLength(); i++){
				inBuffer->ungetChar();
			}
			for(int i = 0; i < con->getLength(); i++){
				outBuffer->putChar(inBuffer->getChar());
			}
			outBuffer->putChar('\n');
		}
		automat->read(inBuffer->getChar());
	}

}
