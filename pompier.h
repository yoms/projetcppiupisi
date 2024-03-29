#ifndef POMPIER_H
#define POMPIER_H
#include "pda.h"
#include "agent.h"

class Pompier : public PDA
{
public:
    Pompier(Plateau* plateau):PDA(plateau){ this->vision = 1; }
    virtual void jouer();
    virtual char* className(){return "Pompier";}
    virtual void transmettre(QList <Agent*> *){};
};

#endif // POMPIER_H
