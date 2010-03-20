#ifndef CAPTEUR_H
#define CAPTEUR_H
#include "secours.h"

class Capteur : public Secours
{
public:
    Capteur(Plateau* plateau);
    void jouer();
    void personneBlesser(int x,int y ){}
    void feu(int x,int y ){}
    char* className(){ return "Capteur"; }
    void transmettre(QList<Agent *> *){}
};

#endif // CAPTEUR_H
