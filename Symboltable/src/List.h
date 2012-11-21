#ifndef __LIST__H__
#define __LIST__H__
#include "Element.h"

/**
 * Listenimplementierung
 * max
 *
 */
template<class TType>
class List {
private:
	int size;
	Element<TType>* first; //Zeiger auf das erste Element
	Element<TType>* last; //Zeiger auf das letzte Element

public:

	//Konstruktor
	List() {
		this->first = 0;
		this->last = 0;
		this->size = -1;

	}

	//Destruktor löscht alle Elemente der Liste
	~List() {
		for (int i = size; i >= 0; i--) {
			this->remove(i);
		}
	}

	//Fügt ein Element an den Anfang der Liste an
	void addFirst(TType value) {
		Element<TType>* newElement = new Element<TType>(value);

		if (this->first != 0) {
			this->first->setPreviousElement(newElement);
			newElement->setNextElement(this->first);

		} else {
			this->last = newElement;
		}
		this->first = newElement;
		this->size++;
	}

	//Fügt ein Element am Ende der Liste an
	void addLast(TType value) {
		Element<TType>* newElement = new Element<TType>(value);

		if (this->last != 0) {
			this->last->setNextElement(newElement);
			newElement->setPreviousElement(this->last);

		} else {
			this->first = newElement;
		}
		this->last = newElement;
		this->size++;
	}

	//gibt den Wert an der Index'ten Stelle zurück
	List* getValueAt(int index) {
		if (index <= this->size && index >= 0) {
			return this->first->getValueAt(index, 0);
		} else {
			throw "List::getValueAt bad index";
		}
	}

	//löscht das Element an der Stelle des Index'es
	void remove(int index) {
		if (index <= this->size && index >= 0) {
			if (this->size == 0) {
				delete this->last;
				this->last = 0;
				this->first = 0;

			} else if (index == this->size) {
				this->last = this->last->getPreviousElement();
				this->last->setNextElement(0);

			} else if (index == 0) {
				this->first = this->first->getNextElement();
				this->first->setPreviousElement(0);

			} else {

				this->first->removeElementAt(index, 0);
			}
			this->size--;
		}
	}

	//gibt die Größe der Liste zurück
	int getSize() {
		return this->size + 1;
	}

	//setzt einen neuen Wert an der Stelle index
	void setValue(int index, TType value) {
		if ((index >= 0) && (index <= this->size)) {
			this->first->setValue(index, 0, value);

		}
	}
};

#endif  //__LIST__H__
