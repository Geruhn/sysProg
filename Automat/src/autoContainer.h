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
    friend class State;

public:
    /*
    autoContainer(int line, int col, int length, int nameLength, char* name, int type) {
        this->line = line;
        this->col = col;
        this->length = length;
        this->nameLenght = nameLength;
        this->name = new char[nameLength + 1];
        for (int i = 0; i < this->nameLenght; i++) {
            this->name[i] = name[i];
        }
        name[nameLength] = '\0';
        if(type>0 || type<4) {
            this->type = type;
        } else {
            this->type = 0;
        }
    };
    */
    autoContainer();
    autoContainer(int line, int col);
    virtual ~autoContainer();

    int getCol();
    int getLine();
    int getType();
    int getLength();
    char* getName();

    void increaseCol();
    void increaseLine();

    void setType(int type);

    /*
    int getNameLength() {
        return this->nameLenght;
    };*/

    

private:
    int col, line, length, type;
    char* name;

};

#endif	/* AUTOCONTAINER_H */

