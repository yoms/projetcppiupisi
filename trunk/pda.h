#ifndef PDA_H
#define PDA_H
#include "agent.h"
#include "plateau.h"
#include "math.h"
class PDA : public Agent
{
public:
    PDA(Plateau* plateau):Agent(plateau){}
    virtual void jouer() = 0;
    virtual char* className(){ return "PDA"; }
    Element* getFeuPlusProche();
    int distance(int x1,int x2,int y1,int y2){return (int)sqrt( ((x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1)));}

};

#endif // PDA_H
