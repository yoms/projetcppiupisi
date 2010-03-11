#ifndef AGENT_H
#define AGENT_H
class Agent;
#include "plateau.h"
#include "element.h"
class Agent
{
private:
    Plateau* plateau;
    Element* element;
public:
    Agent(Plateau* plateau);
    void jouer();
    void lier(Element* element){this->element = element;}
    int getPosX();
    int getPosY();
    char* className(){return "Agent";}
};

#endif // AGENT_H
