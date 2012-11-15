/* 
 * File:   autoContainer.h
 * Author: Andy Perdana
 *
 * Created on 28. Oktober 2012, 14:08
 */

#ifndef AUTOCONTAINER_H
#define	AUTOCONTAINER_H

/*
 * The variable type indicates if the container contains an identifier or a key
 * word (=1), a value (=2), a symbol (=3) of if a failure occured and the 
 * automat tried to submit something unknown (=0). 
 */

class autoContainer {

public: 
    //autoContainer();
    //autoContainer(int line, int col);
    autoContainer(int line, int col, int length, char c, int type);
    virtual ~autoContainer();

    int getCol();
    int getLine();
    int getType();
    int getLength();
    char* getName();

    void increaseCol();
    void increaseLine();

    void setType(int type);

private:
    int col, line, length, type;
    char* name;

};

#endif	/* AUTOCONTAINER_H */

