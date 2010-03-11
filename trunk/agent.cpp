#include "agent.h"

Agent::Agent(Plateau *plateau):plateau(plateau)
{
}
void Agent::jouer()
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
