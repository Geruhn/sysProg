/* 
 * File:   z0.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:15
 */



#include "z0.h"

z0::z0() {

}


State* z0::mkState() {
    if (z0 == NULL) {
    	this = new z0();

    }
    return z0;
}

autoContainer* z0::readChar(Automat* autom, char c) {
    
	if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ){
		autom->increaseCol();
		autom->increaseLength();
		//in z1 gehen
		z1->mk
	}
	if(c=='\n'){
		autom->increaseLine();
	}
    return 0;
}

