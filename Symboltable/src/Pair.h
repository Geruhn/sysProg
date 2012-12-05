#ifndef __PAIR__INCLUDED__
#define __PAIR__INCLUDED__

template<class TType>
class Pair {


public:

	char* lexem;
	TType type;

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

	Pair(char* lexem, TType type) {
		this->lexem = lexem;
		this->type = type;
	}

};

#endif  //__PAIR__INCLUDED__
