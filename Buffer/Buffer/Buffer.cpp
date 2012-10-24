﻿/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *
      Author: knad0001
 */

#include "Buffer.h"


Buffer::Buffer(char *source) {

	bufferLength = 512;
	leftSide = new char[bufferLength+1];
	rightSide = new char[bufferLength+1];
	baseLeft= current = next = &leftSide[0];
	baseRight = &rightSide[0];
	isLeft = true;
	NULL = -1;
	stream = 0;
	fd = 0;
	sourceFile = source;
}

Buffer::~Buffer() {
	delete bufferLength;
	delete leftSide;
	delete rightSide;
}

char Buffer::getChar() {
	current = next; //nimm das zuletzt als nächstes Zeichen gesetzt, als neues aktuelles Zeichen

	if(*current != NULL){
		if(current == baseRight + bufferLength){ //wenn wir uns im letzten Zeichen befinden an
			fillBuffer();						// Anfang von anderem Array wechseln und Buffer füllen
			next = baseLeft;
			isLeft = !isLeft;
		}
		if(current == baseLeft + bufferLength){ //wenn wir uns im letzten Zeiche befinden an
			fillBuffer();                      //Anfang von anderem Array wechseln und Buffer füllen
			next = baseRight;
			isLeft = !isLeft;
		}
		else{
			next++;							  //Aktuelles Zeichen befindet sich iwo mitten im Buffer
		}
		return *current;
	}
	return *current;
}

void Buffer::ungetChar(){

		if(current == baseRight){
			next = &leftSide[bufferLength];
			isLeft = !isLeft;
		}
		else{
			if( current == baseLeft){
				next = &rightSide[bufferLength];
				isLeft = !isLeft;
			}
			else{
				next = next - 2;
			}
		}
}


void Buffer::openFile(){
	// http://phoenix.goucher.edu/~kelliher/cs43/mar26.html
	// http://en.wikipedia.org/wiki/C_file_input/output
	// http://en.cppreference.com/w/cpp/io/basic_fstream/open
	// http://de.wikibooks.org/wiki/C-Programmierung:_Dateien

	fd = open(sourceFile, 00400, O_Direct);
	stream = fdopen(fd, "r+");
}


void Buffer::fillBuffer(){
	int i, r;
	openFile();
	if(isLeft) {
		for (i = 0; ((r = getc(stream)) != "EOF" && i < bufferLength); i++) {
			rightSide[i] = r;
		}
	} else {
		for (i = 0; ((r = getc(stream)) != "EOF" && i < bufferLength); i++){
			leftSide[i] = r;
		}
	}
}