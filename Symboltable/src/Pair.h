#ifndef __PAIR__INCLUDED__
#define __PAIR__INCLUDED__

template<class type>
class Pair {
public:
	Pair(char* key, type value) {
		this->key = key;
		this->value = value;
	}
private:
	char* key;
	type value;

};

#endif  __PAIR__INCLUDED__
