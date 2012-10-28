/* 
 * File:   autoContainer.h
 * Author: andy
 *
 * Created on 28. Oktober 2012, 14:08
 */

#ifndef AUTOCONTAINER_H
#define	AUTOCONTAINER_H

class autoContainer {
public:
    autoContainer(int line, int col, int length, bool isIdentifier) {
        this->line = line;
        this->col = col;
        this->length = length;
        this->isIdentifier = isIdentifier;
    }
    virtual ~autoContainer();
    int getLine() {
        return this->line;
    }
    int getCol() {
        return this->col;
    }
    bool isIdentifier() {
        return this->isIdentifier;
    }
private:
    int col, line, length;
    bool isIdentifier;

};

#endif	/* AUTOCONTAINER_H */

