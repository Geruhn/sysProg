/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef BUFFER_H_
#define BUFFER_H_

//#include <io.h>
#include <stdio.h>
#include <fcntl.h>
//#include <fildes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



class Buffer {

private:
	char *baseLeft;
	char *baseRight;
	char *next;
	char *current;
	char* leftSide;
	char* rightSide;
	char* sourceFile;
	bool isLeft;
	FILE* stream;
	int fd;
	int readVar;
	unsigned int bufferLength;


public:
	Buffer(char* source);
	virtual ~Buffer();
	char getChar();
	void ungetChar();
	void openFile();
	void fillBuffer();
	void writeFile(char* outputFile);
};

#endif /* BUFFER_H_ */
