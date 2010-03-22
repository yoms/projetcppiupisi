#ifndef SECOUR_H
#define SECOUR_H
#include "agent.h"

class Secours : public Agent
{
public:
    Secours(Plateau* plateau):Agent(plateau){}
    virtual void jouer() = 0;
    virtual char* className(){ return "Secour"; }
};

#endif // SECOUR_H
