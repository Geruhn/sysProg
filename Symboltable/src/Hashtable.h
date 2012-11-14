#ifndef __HASHTABLE__INCLUDED__
#define __HASHTABLE__INCLUDED__

#include "Pair.h"
#include "List.h"

//TODO liste in liste implementieren um doppelte Elemente nicht überschreiben zu müssen

using namespace std;

template<class type>
class Hashtable {

	List<Pair<type>*>* table;
	int size;

	//berechnet den Hashcode, key = lexem
	int hashcode(char* key, int lexemLength) {
		int result = 0;
		for (int i = 0; i < lexemLength; i++) {
			result += (result * 42 + key[i]);
		}
		return (result % this->size); //Hash wird zurückgegeben --max
	}

public:

	//Konstruktor
	Hashtable(int nsize) {
		this->size = nsize;
		//
		table = new List<Pair<type>*>* [this->size];
	}

	//Destruktor
	~Hashtable() {
		delete[] this->table;
	}

	//initialisiert Symboltabelle mit Tokens, Folie 52 --max
	void initSymbols() {
		put("print", "PrintToken", 5);
		put("read", "ReadToken", 4);
	}

	//Fügt den Key in die Liste an.
	//Sollte der Key schon vorhanden sein, wird er in der 2ten Liste hinten angehängt --max
	Pair* put(char* lexem, type value, int lengthLexem) {

		//Errechneter Wert aus dem Key/Lexem
		int index = hashcode(lexem, lengthLexem);

		//überflüssig
		//Key schon vorhanden?
		//bool isLexemAlreadyExisting = false;
		//isLexemAlreadyExisting = contains(lexem, lengthLexem);

		Pair<type>* pair;
		Pair<type>* p1 = new Pair<type>(lexem, value);

		//läuft bis zum Index in der Liste
		for (int i = 0; i < table[index].getSize(); i++) {
			pair = table[index].getValueAt(i);
			//sollte der Wert schon vorhanden sein -> Pointer auf das Info Objekt zurückgeben
			if (pair->key == lexem) {
				return pair;
			}

		}
		//Nicht vorhanden, fügt den neuen Wert an die Liste an
		Pair<type>* p1 = new Pair<type>(lexem, value);
		table[index].addLast(p1);
		return p1;
	}

	//Gibt einen Pointer auf das Pair/Info
	Pair* get(char* key, int lengthLexem) {
		int index = hashcode(key, lengthLexem);
		Pair<type>* pair;

		//Läuft die Liste durch bis zum index wo der Wert liegen sollte
		for (int i = 0; i < table[index].getSize(); i++) {
			pair = table[index].getValueAt(i);

			//Wert bereits vorhanden ->  Wert
			if (pair->key == key) {
				return pair;
			}
		}
		//Wert nicht dann vorhanden Fehlermeldung
		return -1;
	}

	bool remove(char* key, int lengthLexem) {
		int index = hashcode(key, lengthLexem);
		Pair<type>* pair;

		for (int i = 0; i < table[index].getSize(); i++) {
			pair = table[index].getValueAt(i);

			if (pair->key == key) {
				table[index].remove(i);
				return true;
			}
		}
		return false;
	}

	//Gibt zurück ob der Key in der 1ten Liste schon vorhanden ist --max
	bool contains(char* key, int lengthLexem) {

		int index = hashcode(key, lengthLexem);
		Pair<type>* pair;

		//durchlaufen bis zum index, falls vorhanden return true, sonst false
		for (int i = 0; i < table[index].getSize(); i++) {
			pair = table[index].getValueAt(i);
			if (pair->key == key) {
				return true;
			}
		}
		return false;
	}

};
#endif  __HASHTABLE__INCLUDED__
