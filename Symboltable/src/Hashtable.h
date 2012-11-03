#ifndef __HASHTABLE__INCLUDED__
#define __HASHTABLE__INCLUDED__

#include "Pair.h"
#include "List.h"


//TODO string durch char* ersetzen
//char* muss 0 terminiert sein! sonst  enth�lt key char* und l�nge des char*


using namespace std;

template <class type>
class Hashtable {
  List<Pair<type>* >* table;	 	
  int size;							

  //berechnet den Hashcode
  unsigned int hashcode(string key) {

	  unsigned int result = 0;
	  for(int i = 0; i < key.size(); i++) {
		  result += (result * 42 + key[i]);
	  }
	  return (result%size);
  }

public:
// Konstruktor
  Hashtable(int nsize) {
	  this->size = nsize;
	  table = new List<Pair<type>* >[size];
  }

  //Destruktor
  ~Hashtable() {
	  delete[] table;
  }

  bool put(string key, type value){
	  int index = hashcode(key);
	  Pair<type>* pair;

	  //l�uft bis zum Index
	  for(int i = 0; i < table[index].getSize(); i++){
		 pair = table[index].getValueAt(i);

		 //sollte der Wert schon vorhanden sein -> true
		 if(pair->key == key){
			pair->value = value;
			return true;
		 }
	  }
	  //f�gt den neuen Wert an die Liste hinten an -> false
	  Pair<type>* p1=new Pair<type>(key, value);
	  table[index].addLast(p1);
	  return false;
  }		

  type get(string key) {
	  int index = hashcode(key);
	  Pair<type>* pair;

	  //L�uft die Liste durch bis zum index wo der Wert liegen sollte
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

  bool remove(string key) {
	  int index = hashcode(key);
	  Pair<type>* pair;

	  for(int i = 0; i < table[index].getSize(); i++) {
		 pair = table[index].getValueAt(i);

		 if(pair->key == key) {
			 table[index].remove(i);
			 return true;
		 }
	  }
	  return false;
  }

  bool contains(string key) { //entspricht lookup
	  int index = hashcode(key);
	  Pair<type>* pair;

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
