/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *
      Author: knad0001
 */

#include "Buffer.h"



Buffer::Buffer(char* source) {
	bufferLength = 512;
	posix_memalign((void**) &(this->leftSide),512,bufferLength );
	posix_memalign((void**) &(this->rightSide),512,bufferLength );

	leftSide = new char[bufferLength+1];
	rightSide = new char[bufferLength+1];
	baseLeft= current = next = &leftSide[0];
	baseRight = &rightSide[0];
	isLeft = true;
	readVar = 0;
	stream = 0;
	fd = 0;
	sourceFile = source;
}

Buffer::~Buffer() {

	delete leftSide;
	delete rightSide;
}

char Buffer::getChar(){
	current = next; //nimm das zuletzt als nächstes Zeichen gesetzt, als neues aktuelles Zeichen

	if(true){
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

	fd = open(sourceFile, O_DIRECT);
	readVar = read(fd ,&leftSide,512);

}


void Buffer::fillBuffer(){
	//int i, r;
	openFile();
	if(isLeft){
		//for (i = 0; ((r = getc(stream)) != -1 && i < bufferLength); i++){
		//		rightSide[i] = r;
		//}
		readVar = read(fd ,&leftSide,512);
		int illl=0;
	}
	else{
		//for (i = 0; ((r = getc(stream)) != -1 && i < bufferLength); i++){
		//	leftSide[i] = r;
		//}
		readVar = read(fd ,&rightSide,512);
	}
}
