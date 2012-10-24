#include "Buffer.h"
#include "iostream"

int main(int argc, char **argv) {

	char zeichen;
	Buffer*  buffer;
	char string[] = "/home/max/myfile.txt";
	buffer = new Buffer(string);
	buffer->openFile();
	buffer->fillBuffer();
	zeichen = buffer->getChar();
	int i=0;


}
