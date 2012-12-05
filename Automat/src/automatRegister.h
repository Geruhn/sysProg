/* 
 * File:   automatRegister.h
 * Author: andy
 *
 * Created on December 5, 2012, 12:34 AM
 */

#ifndef AUTOMATREGISTER_H
#define	AUTOMATREGISTER_H

#include "Automat.h"
#include "StateInterface.h"

class automatRegister {
private:
    Automat* automat;
public:
    automatRegister(const Automat* autom) {
        this->automat = autom;
    }
    void setState(StateInterface* newState) {
        automat->setState(newState);
    }

void ungetChar(const char* c) {
    this->automat->ungetChar(c, 1);
}
void Automat::ungetChar(const char* chars, int arrayLength) {
    this->automat->ungetChar(chars, arrayLength);
}

/** 
 * 
 * @return Pointer to the current autoContainer
 */
autoContainer* getCurrentContainer(){
    return this->automat->getCurrentContainer();
}

autoContainer* Automat::getLastContainer(){
    return this->automat->getLastContainer();
}
};

#endif	/* AUTOMATREGISTER_H */

