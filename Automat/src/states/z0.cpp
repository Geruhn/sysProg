/* 
 * File:   z0.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:15
 */



#include "z0.h"

z0::z0() {

}

<<<<<<< HEAD

State* z0::mkState() {
//    if (z0 == 0) {
        //        this = new z0();
//    }
    
    return 0;
}
autoContainer* z0::readChar(Automat* autom, char c) {
    
=======

static State* z0::mkState() {
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
		autom->setState(z1::mkState());
	}
	if(c=='\n'){
		autom->increaseLine();
	}
>>>>>>> maxbauer
    return 0;
}

