/*
* File: stateStart.cpp
* Author: Andy Perdana
*
* Created on 26. Oktober 2012, 14:15
*/


//#include "../State.h"
#include "stateStart.h"

stateStart::stateStart() {

}

autoContainer* stateStart::readChar(Automat* autom, autoContainer* con, char c) {
	//testen, ob wir am anfang der Datei sind, dann defualt Konstuktor sonst letzten autoContainer nach aktueller zeile etc fragen
    if(con == 0) {
    	if(autom->getLastContainer() == 0){
    		con = new autoContainer();
    	}
    	else{
    		con = new autoContainer(autom->getLastContainer()->getLine(), autom->getLastContainer()->getCol());
    	}
    }
    //Für Identifier
    if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ){
            con->increaseCol();
            autom->setState("Identifier");
            return con;
    }
    //Für Leerzeichen und Zeilenumbrüche
    if( c == '\n' || c == 32){
    	con->increaseLine();
    	autom->setTokenFound(0);
    	return con;
    }
    //Für Zahlen
    if( c >= '0' && c <= '9'){
    	con->increaseCol();
    	autom->setState("Digit");
    	return con;
    }
    return 0;
}

