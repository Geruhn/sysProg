/* 
 * File:   Automat.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:00
 */

#include "Automat.h"
#include "states/z0.h"


Automat::Automat() {
    this->current = new z0();

}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}
