#ifndef VICTIME_H
#define VICTIME_H
#include "pda.h"
#include "agent.h"

class Victime : public PDA, public Agent
{
public:
    Victime(Plateau* plateau):Agent(plateau){}
    virtual void jouer();
    virtual char* className(){return "Victime";}
    virtual void delAgent(){}
};

#endif // VICTIME_H
