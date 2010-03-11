#ifndef FEU_H
#define FEU_H
class Feu;
#include "plateau.h"
#include <QString>
class Feu
{
private:
    Plateau* plateau;
public:
    Feu(Plateau* plateau);
    void jouer();
    char* className(){ return "Feu";}
};

#endif // FEU_H
