/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//nur zum Testen eingefügt -Reinsch
#include <iostream>
using namespace std;

class Buffer {

private:
	char *baseLeft;
	char *baseRight;
	char *next;
	char *current;
	char* leftSide;
	char* rightSide;
	char* sourceFile;
	int fdRe;
	int fdWr;
	int eof;
	bool isEOF;
	bool isLeft;
	bool isFileOpen;
	unsigned int bufferLength;
	void fillBuffer();
	void createFile();
	void openFile();

public:
	Buffer(char* source);
	virtual ~Buffer();
	char getChar();
	void ungetChar();
	void putChar(char c);
	bool hasNext();
	void closeFiles();

};

#endif /* BUFFER_H_ */
