/* 
 * File:   stateStart.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:15
 */


//#include "../State.h"
#include "stateStart.h"

stateStart::stateStart() {

}

autoContainer* stateStart::readChar(Automat* autom, char c) {
    
	if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ){
		autom->increaseCol();
		autom->increaseLength();
		//in z1 gehen
		autom->setState(z1::mkState());
	}
	if(c=='\n'){
		autom->increaseLine();
	}

    return 0;
}

