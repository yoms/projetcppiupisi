#ifndef PDA_H
#define PDA_H
#include "agent.h"
#include "plateau.h"
class PDA : public Agent
{
public:
    PDA(Plateau* plateau):Agent(plateau){}
    virtual void jouer() = 0;
    virtual char* className(){ return "PDA"; }
    Element* getFeuPlusProche();        
};

#endif // PDA_H
