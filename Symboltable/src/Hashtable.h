#ifndef __HASHTABLE__INCLUDED__
#define __HASHTABLE__INCLUDED__

#include "Pair.h"
#include "List.h"

//TODO liste in liste implementieren um doppelte Elemente nicht überschreiben zu müssen

using namespace std;

template<class type>
class Hashtable {

	List<List<Pair<type>*> >* table;
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
		table = new List<List<Pair<type>*> > [this->size];
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

	//
	int put(char* key, type value, int lengthLexem) {
		int index = hashcode(key, lengthLexem);
		bool isLexemAlreadyExisting = false;

		Pair<type>* pair;

		isLexemAlreadyExisting = contains(key,lengthLexem);

		// key/lexem schon vorhanden

		// key/lexem noch nicht vorhanden
		Pair<type>* p1 = new Pair<type>(key, value);


		//läuft bis zum Index in der 1ten Liste
		for (int i = 0; i < table[index].getSize(); i++) {
			pair = table[index].getValueAt(i);

			//sollte der Wert schon vorhanden sein -> true
			if (pair->key == key) {
				pair->value = value;
				return true;
			}
		}
		//fügt den neuen Wert an die Liste hinten an -> false
		Pair<type>* p1 = new Pair<type>(key, value);
		table[index].addLast(p1);

		return index;
	}

	type get(char* key, int lengthLexem) {
		int index = hashcode(key, lengthLexem);
		Pair<type>* pair;

		//Läuft die Liste durch bis zum index wo der Wert liegen sollte
		for (int i = 0; i < table[index].getSize(); i++) {
			pair = table[index].getValueAt(i);

			//Wert bereits vorhanden ->  Wert
			if (pair->key == key) {
				return pair->value;
			}
		}
		//Wert nicht vorhanden Fehlermeldung
		throw "Key nicht vorhanden";
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

	//gibt zurück ob das lexem in der 1ten Liste schon vorhanden ist
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
