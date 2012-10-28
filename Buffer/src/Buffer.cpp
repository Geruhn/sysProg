/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *
 Author: knad0001
 */

//TODO geöffnetes File muss noch geschlossen werden.
//TODO Ende der Datei erkennen um sie zu schließen.
//TODO Da immer 512 Pakte übergeben werden muss wenn nicht mehr genug da Rest iwie gefüllt werden.

/*
 * couts hinzugefügt zum debuggen - Reinsch
 */

#include "Buffer.h"

Buffer::Buffer(char* source) {
	bufferLength = 512;

	leftSide = new char[bufferLength + 1];
	rightSide = new char[bufferLength + 1];

	//Speicher für die 2 Buffer holen
	posix_memalign((void**) &(this->leftSide), 512, bufferLength);
	posix_memalign((void**) &(this->rightSide), 512, bufferLength);

	eof = 10;
	fdRe = fdWr = 0;
	baseLeft = current = next = &leftSide[0];
	baseRight = &rightSide[0];
	isLeft = true;
	isFileOpen = isEOF = false;
	sourceFile = source;
}

Buffer::~Buffer() {
	delete leftSide;
	delete rightSide;
}

char Buffer::getChar() {
	current = next; //nimm das zuletzt als nächstes Zeichen gesetzt, als neues aktuelles Zeichen -Reinsch

	if(!isFileOpen){ // Wenn noch keine Datei geöffnet oder erstellt wurde. -Reinsch
		openFile();
		fillBuffer();
	}

	if(*current == eof){ //Testen ob Datei zuende ist. -Reinsch
		isEOF = true;
		close(fdRe);
		return *current;
	}

	if (true) { //abfangen ob current außerhalb des Speichers der 2 buffer ist "!((&current < &leftSide[0]) && (&current > &leftSide[bufferLength - 1]))"
		if (current == baseRight + bufferLength - 1) { //wenn wir uns im letzten Zeichen befinden an
			isLeft = true;
			fillBuffer(); //Linke Seite neu befüllen
			next = baseLeft;
			return *current;
		}
		if (current == baseLeft + bufferLength - 1) { //wenn wir uns im letzten Zeichen befinden an
			isLeft = false;
			fillBuffer(); //Rechte Seite neu befüllen
			next = baseRight;
			return *current;
		}
		next++; //Aktuelles Zeichen befindet sich iwo mitten im Buffer
		return *current;
	}
	//Fehlerfall - Zeiger befindet sich außerhalb des Speicherbereichs der Arrays - Reinsch
	cout << endl << "!!! ZEIGER AUSERHALB DES SPEICHERBEREICHES !!!" << endl;
	return '\n';
}

void Buffer::ungetChar() {
	if (current == baseRight) { //current steht am anfang von rechts -max
		next = &leftSide[bufferLength - 1];
		isLeft = true;
	} else if (current == baseLeft) { //current steht am anfang von links -max
		next = &rightSide[bufferLength - 1];
		isLeft = false;
	} else { //current steht irgendwo in der mitte -max
		next--;
	}
	current = next;
}

void Buffer::openFile() {
	//cout << endl << "in Buffer::openFile()" << endl;
	fdRe = open(sourceFile, O_DIRECT);
	if(fdRe != -1){	//öffnen der Datei hat geklappt. setze isFileOpen auf true
		isFileOpen = true;
	}
}

void Buffer::createFile() {
	cout << endl << "in Buffer::createFile" << endl;
	fdWr = creat(sourceFile, O_DIRECT);
	if(fdWr != -1){
		isFileOpen = true;
	}else{
		cout << endl << "!!! FEHLER BEIM ERSTELLEN DER DATEI FD: " << fdWr << " !!!" << endl;
	}
}

void Buffer::fillBuffer() {
	//cout << endl << "in Buffer::fillBuffer()" << endl;
	if (isLeft) {
		read(fdRe, baseLeft, 512); //evtl noch hochzählen also ein vielfaches von 512, für die nächsten 512 zeichen -Max
	} else {
		read(fdRe, baseRight, 512); //siehe oben
	}
}

//Bekommt einzelne Zeichen, speichert sie zwischen und schreibt sie wenn das Array voll ist in die Datei -Reinsch
void Buffer::putChar(char c){
	current = next;

	//cout << *current << endl;
	if(!isFileOpen){
		createFile();
	}

	if(c == eof){ //Letztes Zeiches
		*current = c; //Rest in Datei schreiben
		if(isLeft){ //Schauen das Reihenfolge beim schreiben stimmt.
			if(*baseRight != NULL){
				write(fdWr, baseRight, bufferLength);
			}
			write(fdWr, baseLeft, bufferLength);
		}
		else{
			if(*baseLeft){
				write(fdWr, baseLeft, bufferLength);
			}
			write(fdWr, baseRight, bufferLength);
		}
		cout << endl << "Close File" << endl;
		int test = close(fdWr);
		if(test == -1){
			cout << "fehler beim schließen der Datei";
		}
	}
	else{
		//Fülle so lange linkes Array bis es voll ist. Danach das Rechte. Ist das voll wird das Linke geschrieben usw.
		if(current == baseLeft + (bufferLength -1)){
			if(*baseRight != NULL){ //das kein leeres Array in Datei geschrieben wird
				write(fdWr, baseRight, bufferLength);
			}
			cout << "Linke Seite voll" << endl;
			next = baseRight;
			isLeft = false;
			*current = c;
			cout << *current;
			return;
		}
		if(current == baseRight + (bufferLength -1)){
			if(*baseLeft != NULL){ //das kein leeres Array in Datei geschrieben wird
				write(fdWr, baseLeft, bufferLength);
			}
			cout << "Rechte Seite voll" << endl;
			next = baseLeft;
			isLeft = true;
			*current = c;
			cout << *current;
			return;
		}
		next++;
		*current = c;
		cout <<  *current;
	}
}

bool Buffer::hasNext(){
	return !isEOF;
}

void Buffer::closeFiles(){ //schließt die geöffneten Dateien wieder -max
	close(fdRe);
	close(fdWr);
}
