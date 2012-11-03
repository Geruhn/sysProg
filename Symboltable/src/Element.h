#ifndef __ELEMENT__H__
#define __ELEMENT__H__

/**
*Element der Liste
*
*/
template <class type>
class Element {
public:
	type value;
	Element* next;
	Element* previous;

	Element(type value) {
		this->value=value;
	}
	
	~Element() {
		
	}
	
	void setNextElement(Element* next){
		this->next = next;
	}
	
	void setPreviousElement(Element* previous){
		this->previous = previous;
	}
	
	Element* getNextElement(){
		return this->next;
	}
	
	Element* getPreviousElement(){
		return this->previous;
	}
	
	type getValueAt(int index, int offset){
		if (index == offset){
			return this->value;
		} else {
			return this->next->getValueAt(index, offset + 1);
		}
	}
	
	void removeElementAt(int index, int offset){
		if (index-1 == offset){
			Element* temp = this->next;
			this->next = temp->getNextElement();
			temp->next->setPreviousElement(this);
			temp->setNextElement(0);
			temp->setPreviousElement(0);
			delete temp;
		} else{
			this->next->removeElementAt(index, offset+1);
		}
	}
		
	void setValue(int index, int offset, type value){
		if(index == offset){
			this->value = value;
		} else{
			this->next->setValue(index, offset+1, value);
		}
	}
};
#endif // __ELEMENT__H__