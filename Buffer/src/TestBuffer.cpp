#include "Buffer.h"

int main(int argc, char **argv) {
	char stringInput[] = "/home/andy/sysProg/text.txt";
	char stringOutput[] = "/home/andy/sysProg/writeFile.txt";
	Buffer* inBuffer = new Buffer(stringInput);
	Buffer* outBuffer = new Buffer(stringOutput);

	for(int i = 0; i < 10000 && inBuffer->hasNext(); i++){
		outBuffer->putChar(inBuffer->getChar());
	}
	//inBuffer->closeFiles(); //Dateien wieder schließen --max
	return 0;
}
