/* 
 * File:   autoContainer.h
 * Author: Andy Perdana
 *
 * Created on 28. Oktober 2012, 14:08
 */

#ifndef AUTOCONTAINER_H
#define	AUTOCONTAINER_H

class autoContainer {
public:
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
        this->type = type;
    };
    virtual ~autoContainer();
    int getLine() {
        return this->line;
    };
    int getCol() {
        return this->col;
    };
    int getLength() {
        return this->length;
    }
    int getNameLength() {
        return this->nameLenght;
    }
    char* getName() {
        return this->name;
    }
    int getType() {
        return this->type;
    };
    
private:
    int col, line, length, nameLenght, type;
    char* name;

};

#endif	/* AUTOCONTAINER_H */

