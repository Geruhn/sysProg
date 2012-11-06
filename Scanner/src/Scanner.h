/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include"Buffer.h"
#include"Automat.h"
#include"Hashtable.h"

class Scanner {
public:
	Scanner();
	void runScanner();
	virtual ~Scanner();
};

#endif /* SCANNER_H_ */
