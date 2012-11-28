/*
* File: stateIdentifier.cpp
* Author: Andy Perdana
*
* Created on 30. Oktober 2012, 11:36
*/

#include "stateIdentifier.h"
#include "../autoContainer.h"

//type = 1
stateIdentifier::stateIdentifier() {

}

autoContainer* stateIdentifier::readChar(Automat* autom, autoContainer* con, char c) {
	if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || (c >= '0' && c <= '9')){

		con->increaseCol();
		return con;
	}
	if(c == '\n' | c == 32){
//		autom->setTokenFound(1);
		autom->setState("Start");
	}
	else{//error
		con->increaseCol();
//		autom->setTokenFound(-1);
		autom->setState("Start");
	}
    return 0;
}

void stateIdentifier::startState(State* states, int arrayLength) {
    
}
