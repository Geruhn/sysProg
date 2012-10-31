/* 
 * File:   z1.cpp
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#include "z1.h"


z1::z1() {

}


static State* z1::mkState() {
    if (theStateZ1 == NULL) {
    	this->theStateZ1 = new z1();
    }
    return theStateZ1;
}

autoContainer* z1::readChar(Automat* autom, char c) {

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

