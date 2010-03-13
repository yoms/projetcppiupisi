#ifndef AGENT_H
#define AGENT_H
class Agent;
#include "plateau.h"
#include "element.h"
class Agent
{
protected:
    Plateau* plateau;
    Element* element;
public:
    Agent(Plateau* plateau);
    virtual void jouer() = 0;
    void lier(Element* element){this->element = element;}
    int getPosX();
    int getPosY();
    virtual char* className(){return "Agent";}
    virtual void delAgent(){}
};

#endif // AGENT_H
