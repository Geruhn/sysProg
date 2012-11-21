#ifndef __HASHTABLE__INCLUDED__
#define __HASHTABLE__INCLUDED__

#include "Pair.h"
#include "List.h"
#include <string.h>


//TODO string durch char* ersetzen
//char* muss 0 terminiert sein! sonst key enthält char* und länge des char*



using namespace std;

template <class TType>
class Hashtable {
  List<Pair<TType>* >* table;
  int size;

  //berechnet den Hashcode, key = lexem
  	int hashcode(char* key) {

  		size_t lexemLength = strlen(key);;

  		//hashfunction f(a ...an) = (16 c1 + 8 c n + n) mod m
  		int result = 0;
  		char* positionString;
  		positionString = key;

  		//erstes Zeichen
  		result = result + (16 * (*positionString));
  		//letztes Zeichen, falls lexem > 1
  		if (lexemLength > 1) {
  			positionString += lexemLength - 1;
  			result = result + (8 * (*positionString));
  		}
  		result += lexemLength;

  		//Hash wird zurückgegeben
  		return (result % this->size);
  	}

public:
// Konstruktor
  Hashtable(int nsize) {
	  this->size = nsize;
	  table = new List<Pair<TType>* >[size];
  }

  //Destruktor
  ~Hashtable() {
	  delete[] table;
  }

  bool put(char* key, TType value){
	  int index = hashcode(key);
	  Pair<TType>* pair;

	  //läuft bis zum Index
	  for(int i = 0; i < table[index].getSize(); i++){
		 pair = table[index].getValueAt(i);

		 //sollte der Wert schon vorhanden sein -> true
		 if(pair->key == key){
			pair->value = value;
			return true;
		 }
	  }
	  //fülgt den neuen Wert an die Liste hinten an -> false
	  Pair<TType>* p1=new Pair<TType>(key, value);
	  table[index].addLast(p1);
	  return false;
  }

  TType get(char* key) {
	  int index = hashcode(key);
	  Pair<TType>* pair;

	  //Läuft die Liste durch bis zum index wo der Wert liegen sollte
	  for(int i = 0; i < table[index].getSize(); i++) {
		 pair = table[index].getValueAt(i);

		 //Wert bereits vorhanden -> Wert
		 if(pair->key == key) {
			 return pair->value;
		 }
	  }
	  //Wert nicht vorhanden Fehlermeldung
	  throw "Key nicht vorhanden";
  }

  bool remove(char* key) {
	  int index = hashcode(key);
	  Pair<TType>* pair;

	  for(int i = 0; i < table[index].getSize(); i++) {
		 pair = table[index].getValueAt(i);

		 if(pair->key == key) {
			 table[index].remove(i);
			 return true;
		 }
	  }
	  return false;
  }

  bool contains(char* key) { //entspricht lookup
	  int index = hashcode(key);
	  Pair<TType>* pair;

	  for(int i = 0; i < table[index].getSize(); i++) {
		 pair = table[index].getValueAt(i);
		 if(pair->key == key) {
			return true;
		 }
	  }
	  return false;
  }
};

#endif // __HASHTABLE__INCLUDED__
