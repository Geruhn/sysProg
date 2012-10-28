/* 
 * File:   State.h
 * Author: andy
 *
 * Created on 26. Oktober 2012, 14:00
 */

#ifndef STATE_H
#define	STATE_H

class State {
public:
    State* mkState();
    State(const State& orig);
    virtual ~State();
    virtual void readChar(Automat* autom, char c) = 0;
private:
    State();

};

#endif	/* STATE_H */

