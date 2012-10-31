/* 
 * File:   State.h
 * Author: Andy Perdana
 *
 * Created on 26. Oktober 2012, 14:00
 */

#ifndef STATE_H
#define	STATE_H
#include "autoContainer.h"
class Automat;

class State {
public:
<<<<<<< HEAD
    virtual State* mkState();
=======
	virtual State* mkState();
>>>>>>> maxbauer
    virtual ~State();
    virtual autoContainer* readChar(Automat* autom, char c);
    State();

private:

};

#endif	/* STATE_H */

