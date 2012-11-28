/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef TOKEN_H_
#define TOKEN_H_

class Token {

private:
	int col;
	int line;
	int type;
	autoContainer* infoContainer;

public:
	Token(int type, int line, int col, autoContainer* infoContainer);
	virtual ~Token();

	int getLine();
	int getCol();
	int getType();
	autoContainer* getInfoContainer();
};

#endif /* SCANNER_H_ */
