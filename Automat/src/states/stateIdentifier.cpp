/* 
 * File:   stateIdentifier.cpp
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#include "./stateIdentifier.h"


stateIdentifier::stateIdentifier() {

}

autoContainer* stateIdentifier::readChar(Automat* autom, autoContainer* con, char c) {
	if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ){
		con->increaseCol();
	}
	else{
		//iwie beim buffer ungetChar machen.
		//autom->setState(iwie in startzustand gehen)
	}
    return 0;
}
