/*
 *
 *
 */

#include "stateDigit.h"
#include "../autoContainer.h"
//type = 2
stateDigit::stateDigit() {

}

autoContainer* stateDigit::readChar(Automat* autom, const char* c) {
	if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || (c >=  '0' && c <= '9')){
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

void stateDigit::startState(State* states, int arrayLength) {
    
}
