/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include"../../Buffer/src/Buffer.h"
#include"../../Automat/src/Automat.h"
#include"../../Symboltable/src/Hashtable.h"

class Scanner {
public:
	Scanner();
	void runScanner();
	virtual ~Scanner();
};

#endif /* SCANNER_H_ */
