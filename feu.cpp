#include "feu.h"

Feu::Feu(Plateau* plateau):plateau(plateau)
{
    this->element = NULL;
}

void Feu::jouer()
{
       plateau->deplacer(this);
}

int Feu::getPosX()
{
    return this->element->getX();
}
int Feu::getPosY()
{
    return this->element->getY();
}
