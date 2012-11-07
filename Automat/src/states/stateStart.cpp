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

autoContainer* stateStart::readChar(Automat* autom, autoContainer* con, char c) {
    if(con == 0) { //testen, ob wir am anfang der Datei sind, dann defualt Konstuktor sonst letzten autoContainer nach aktueller zeile etc fragen
    	if(autom->getLastContainer() == 0){
    		con = new autoContainer();
    	}
    	else{
    		con = new autoContainer(autom->getLastContainer()->getLine(), autom->getLastContainer()->getCol());
    	}
    }
    if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ){
            con->increaseCol();
            //autom->setState(iwie in stateIdentifier gehen);
            return con;
    }
    if( c == '\n'){
    	con->increaseLine();
    	con->setType(0);
    	autom->setTokenFound();
    	return con;
    }
    return 0;
}

