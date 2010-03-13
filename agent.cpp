#include "agent.h"

Agent::Agent(Plateau *plateau):plateau(plateau)
{
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
