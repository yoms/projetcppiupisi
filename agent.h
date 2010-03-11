#ifndef AGENT_H
#define AGENT_H
#include "plateau.h"
class Agent
{
private:
    Plateau* plateau;
public:
    Agent(const Plateau* plateau);
    void jouer();
};

#endif // AGENT_H
