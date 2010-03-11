#ifndef FEU_H
#define FEU_H
class Feu;
#include "plateau.h"
#include "element.h"
#include <QString>
class Feu
{
private:
    Plateau* plateau;
    Element* element;
public:
    Feu(Plateau* plateau);
    void jouer();
    void lier(Element* element){this->element = element;}
    int getPosX();
    int getPosY();
    char* className(){ return "Feu";}
};

#endif // FEU_H
