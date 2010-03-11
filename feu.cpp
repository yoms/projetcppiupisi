#include "feu.h"

Feu::Feu(Plateau* plateau):plateau(plateau)
{}
void Feu::jouer()
{
}

int Feu::getPosX()
{
    return this->element->getX();
}
int Feu::getPosY()
{
    return this->element->getY();
}
