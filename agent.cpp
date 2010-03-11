#include "agent.h"

Agent::Agent(Plateau *plateau):plateau(plateau)
{
}
void Agent::jouer()
{
    this->plateau->deplacer( this , 1 , 1 );
}

int Agent::getPosX()
{
    return this->element->getX();
}
int Agent::getPosY()
{
    return this->element->getY();
}
