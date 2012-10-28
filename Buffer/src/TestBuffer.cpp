#include "Buffer.h"

int main(int argc, char **argv) {
	int x = 1;
	int ascii = 0;
	char zeichen;
	char stringInput[] = "/home/max/myFile.txt";
	char stringOutput[] = "/home/max/writeFile.txt";
	Buffer* inBuffer = new Buffer(stringInput);
	Buffer* outBuffer = new Buffer(stringOutput);

	for(int i = 0; i < 10000 && inBuffer->hasNext(); i++){
		zeichen = inBuffer->getChar();
		outBuffer->putChar(zeichen);
		if(i == (50*x)){				//Alle 30 Zeichen einen Zeilenumbruch machen; -Reinsch
			cout << zeichen << endl;
			x++;
		}
		else{
			cout << zeichen;
		}
	}
	inBuffer->closeFiles(); //Dateien wieder schließen --max
	return 0;
}
