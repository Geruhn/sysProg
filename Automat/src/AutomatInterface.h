/* 
 * File:   AutomatInterface.h
 * Author: andy
 *
 * Created on November 23, 2012, 8:17 PM
 */

#ifndef AUTOMATINTERFACE_H
#define	AUTOMATINTERFACE_H
/**
 * Wird gebraucht um den Fehler durch die Inkludierung von Automat.h in State 
 * und State.h in Automat. 
 * --->Circular including is bullshit because it doesn't work because--->
 */
class AutomatInterface {
public:
    enum enumState {
        start,
        identifier,
        digit
        
    };
    virtual void read(const char* c) = 0;
    virtual void ungetChar(const char* c) = 0;
    virtual void ungetChar(const char* chars, int arrayLength) = 0;
    virtual autoContainer* getCurrentContainer() = 0;
    virtual autoContainer* getLastContainer() = 0;

};

#endif	/* AUTOMATINTERFACE_H */

