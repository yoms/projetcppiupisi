#include "agent.h"

Agent::Agent(Plateau *plateau):plateau(plateau)
{
    this->vision = 1;
}


int Agent::getPosX()
{
    return this->element->getX();
}
int Agent::getPosY()
{
    return this->element->getY();
}
void Agent::delAgent()
{
    this->plateau->supElement(this);
}
