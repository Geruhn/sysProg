#include "Buffer.h"


int main(int argc, char **argv) {

	Buffer*  buffer;
	char string[] = "/home/max/myfile.txt";
	buffer = new Buffer(string);
	buffer->getChar();

}
