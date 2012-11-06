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
    autoContainer();
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
    virtual ~autoContainer();
    void increaseCol() {
        this->col++;
    }
    void increaseLine() {
        this->line++;
    }
    void increaseLength() {
        this->length++;
    }
    void increaseNameLength() {
        this->nameLenght++;
    }
    int getCol() {
        return this->col;
    };
    int getLine() {
        return this->line;
    };
    int getLength() {
        return this->length;
    }
    int getNameLength() {
        return this->nameLenght;
    }
    int getType() {
        return this->type;
    };
    char* getName() {
        return this->name;
    }
    
private:
    int col, line, length, nameLenght, type;
    char* name;

};

#endif	/* AUTOCONTAINER_H */

