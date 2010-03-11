#ifndef AGENT_H
#define AGENT_H
class Agent;
#include "plateau.h"
class Agent
{
private:
    Plateau* plateau;
public:
    Agent(Plateau* plateau);
    void jouer();
    char* className(){return "Agent";}
};

#endif // AGENT_H
