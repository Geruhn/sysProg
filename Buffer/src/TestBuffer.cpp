#include "Buffer.h"

int main(int argc, char **argv) {
	char stringInput[] = "text.txt";
	char stringOutput[] = "writeFile.txt";
	Buffer* inBuffer = new Buffer(stringInput);
	Buffer* outBuffer = new Buffer(stringOutput);

	for(int i = 0; i < 10000 && inBuffer->hasNext(); i++){
		outBuffer->putChar(inBuffer->getChar());
	}

//	while(inBuffer->hasNext()){
//		outBuffer->putChar(inBuffer->getChar());
//	}

	return 0;
}
