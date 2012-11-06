#ifndef __PAIR__INCLUDED__
#define __PAIR__INCLUDED__

template<class type>
class Pair {
public:
	char* key;
	type value;

	Pair(char* key, type value) {
		this->key = key;
		this->value = value;
	}

};

#endif  __PAIR__INCLUDED__
