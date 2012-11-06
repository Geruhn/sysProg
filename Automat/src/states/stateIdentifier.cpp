/* 
 * File:   z1.cpp
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#include "stateIdentifier.h"


stateIdentifier::stateIdentifier() {

}

autoContainer* stateIdentifier::readChar(Automat* autom, char c) {

	if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ){ //buchstabe bekommen -max
		autom->increaseCol();
		autom->increaseLength();
		//in z1 bleiben
	}
	if(c=='\n'){						//neue zeile -max
		autom->increaseLine();
		autom->resetCol();
		autom->resetLength();
	}
    return 0;
}
