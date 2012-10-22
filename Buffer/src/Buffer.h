/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <fildes.h>
#include <stdio.h>
#include <stdlib.h>



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
	unsigned int bufferLength;
	unsigned int NULL;
	void openFile();
	void fillBuffer();

public:
	Buffer(char *sourceFile);
	virtual ~Buffer();
	char getChar();
	void ungetChar();
};

#endif /* BUFFER_H_ */
