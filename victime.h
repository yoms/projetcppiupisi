#ifndef VICTIME_H
#define VICTIME_H
#include "pda.h"
#include "agent.h"

enum Etat {VALIDE = 0,BLESSER = 1,SAUVER = 2};
class Victime : public PDA
{
private:
    Etat etat;
public:
    Victime(Plateau* plateau, Etat etat = VALIDE):PDA(plateau),etat(etat){ this->vision = 1; }
    virtual void jouer();
    virtual char* className(){return "Victime";}
    virtual void transmettre(QList <Agent*> *){};
};

#endif // VICTIME_H
