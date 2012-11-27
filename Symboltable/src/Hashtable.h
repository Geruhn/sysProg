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
  	int hashcode(char* lexem) {

  		size_t lexemLength = strlen(lexem);;

  		//hashfunction f(a ...an) = (16 c1 + 8 c n + n) mod m
  		int result = 0;
  		char* positionString;
  		positionString = lexem;

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

  bool put(char* lexem, TType type){
	  int index = hashcode(lexem);
	  Pair<TType>* pair;

	  //läuft bis zum Index
	  for(int i = 0; i < table[index].getSize(); i++){
		 pair = table[index].getValueAt(i);

		 //sollte der Wert schon vorhanden sein -> true
		 if(pair->lexem == lexem){
			pair->type = type;

			return true;
		 }
	  }
	  //fülgt den neuen Wert an die Liste hinten an -> false
	  Pair<TType>* p1=new Pair<TType>(lexem, type);
	  table[index].addLast(p1);
	  return false;
  }

  TType get(char* lexem) {
	  int index = hashcode(lexem);
	  Pair<TType>* pair;

	  //Läuft die Liste durch bis zum index wo der Wert liegen sollte
	  for(int i = 0; i < table[index].getSize(); i++) {
		 pair = table[index].getValueAt(i);

		 //Wert bereits vorhanden -> Wert
		 if(pair->lexem == lexem) {
			 return pair->type;
		 }
	  }
	  //Wert nicht vorhanden Fehlermeldung
	  throw "Key nicht vorhanden";
  }

  //wird nicht benötigt
  bool remove(char* lexem) {
	  int index = hashcode(lexem);
	  Pair<TType>* pair;

	  for(int i = 0; i < table[index].getSize(); i++) {
		 pair = table[index].getValueAt(i);

		 if(pair->lexem == lexem) {
			 table[index].remove(i);
			 return true;
		 }
	  }
	  return false;
  }

  bool contains(char* lexem) { //entspricht lookup
	  int index = hashcode(lexem);
	  Pair<TType>* pair;

	  for(int i = 0; i < table[index].getSize(); i++) {
		 pair = table[index].getValueAt(i);
		 if(pair->lexem == lexem) {
			return true;
		 }
	  }
	  return false;
  }
};

#endif // __HASHTABLE__INCLUDED__
