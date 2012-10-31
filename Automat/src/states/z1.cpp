/* 
 * File:   z1.cpp
 * Author: Andy Perdana
 * 
 * Created on 30. Oktober 2012, 11:36
 */

#include "z1.h"


z1::z1() {

}


State* z1::mkState() {
    if (z1 == NULL) {
    	this = new z1();

    }
    return z0;
}

autoContainer* z1::readChar(Automat* autom, char c) {

	if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ){
		autom->increaseCol();
		autom->increaseLength();
		//in z1 bleiben
	}
	if(c=='\n'){
		autom->increaseLine();
	}
    return 0;
}

