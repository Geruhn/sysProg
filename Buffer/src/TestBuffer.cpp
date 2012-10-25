#include "Buffer.h"

int main(int argc, char **argv) {

	char zeichen;
	Buffer*  buffer;
	char stringInput[] = "/home/max/myfile.txt";
	char stringOutput[] = "/home/max/writeFile.txt";

	buffer = new Buffer(stringInput);
	buffer->openFile();
	buffer->fillBuffer();
	buffer->writeFile(stringOutput);
	//zeichen = buffer->getChar();
	int i=0;


}
