/* 
 * File:   autoContainer.h
 * Author: Andy Perdana
 *
 * Created on 28. Oktober 2012, 14:08
 */

#ifndef AUTOCONTAINER_H
#define	AUTOCONTAINER_H

/*
 * Type | Symbol/Token
 *  -1  | Error
 *   0  | Leerzeichen/Zeilenumbruch
 *   1  | Identifier
 *   2  | Digit
 *   3  | Plus
 *   4  | Minus
 *   5  | Slash
 *   6  | Star
 *   7  | SmallerAs
 *   8  | BiggerAs
 *   9  | Equals
 *  10  | Unequals
 *  11  | Ausrufezeichen
 *  12  | And
 *  13  | Semikolon
 *  14  | OR
 *  15  | Klammerauf
 *  16  | Klammerzu
 *  17  | Geschweifteklammerauf
 *  18  | Geschweifteklammerzu
 *  19  | Eckigeklammerauf
 *  20  | Eckigeklammerzu
 *
 */

class autoContainer {

public: 
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

private:
    int col, line, length, type;
    char* name;

};

#endif	/* AUTOCONTAINER_H */

