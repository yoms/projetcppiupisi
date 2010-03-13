#ifndef PDA_H
#define PDA_H
#include "agent.h"
#include "plateau.h"
class PDA
{
    Element** grille;
public:
    PDA(Element** grille = NULL):grille(grille){}
};

#endif // PDA_H
