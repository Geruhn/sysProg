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

	leftSide = new char[bufferLength+1];
	rightSide = new char[bufferLength+1];

	//Speicher für die 2 Buffer holen
	posix_memalign((void**) &(this->leftSide),512,bufferLength );
	posix_memalign((void**) &(this->rightSide),512,bufferLength );

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

	if(true){ //abfangen ob current außerhalb des Speichers der 2 buffer ist (&current < &leftSide[0]) && (&current > &leftSide[511])
		if(current == baseRight + bufferLength){ //wenn wir uns im letzten Zeichen befinden an
			isLeft = true;
			fillBuffer();						//Linke Seite neu befüllen
			next = baseLeft;
		}
		if(current == baseLeft + bufferLength){ //wenn wir uns im letzten Zeichen befinden an
			isLeft = false;
			fillBuffer();                      //Rechte Seite neu befüllen
			next = baseRight;
		}
		else{
			next++;							  //Aktuelles Zeichen befindet sich iwo mitten im Buffer
		}
		return *current;
	}
	return *current;
}

void Buffer::ungetChar(){

		if(current == baseRight){ //current steht am anfang von rechts
			next = &leftSide[bufferLength];
			isLeft = !isLeft;
		}else if( current == baseLeft){ //current steht am anfang von links
				next = &rightSide[bufferLength];
				isLeft = !isLeft;
		}else{	//current steht irgendwo in der mitte
				next--;		//current eine stelle zurückgestellt
		}

}


void Buffer::openFile(){

	fd = open(sourceFile, O_DIRECT);
	//readVar = read(fd ,&leftSide,512);

}

//
//	schreibt den Buffer in eine Textdatei
//	noch nicht ganz
void Buffer::writeFile(char* outputFile){
	int fdWr;
	fdWr = creat(outputFile, O_DIRECT );
	write(fdWr,&this->leftSide,512);
	//close(fdWr);

}


void Buffer::fillBuffer(){

	if(isLeft){
		readVar = read(fd ,&leftSide,512);//evtl noch hochzählen also ein vielfaches von 512, für die nächsten 512 zeichen
	}
	else{
		readVar = read(fd ,&rightSide,512);//siehe oben
	}
}
