/* 
 * File:   State.cpp
 * Author: Andy Perdana
 * 
 * Created on 26. Oktober 2012, 14:00
 */

#include "State.h"

State::State() {
}

State::~State() {
}

virtual State* State::mkState() {

}

autoContainer* State::readChar(Automat* autom, char c) {
    return 0;
}
