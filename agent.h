#ifndef AGENT_H
#define AGENT_H
class Agent;

#include "plateau.h"
#include "element.h"
#include "math.h"

class Agent
{
protected:
    Plateau* plateau;
    Element* element;
    int vision;
public:
    Agent(Plateau* plateau);
    virtual void jouer() = 0;
    void lier(Element* element){this->element = element;}
    int getPosX();
    int getPosY();
    int getVision(){return this->vision;}
    virtual char* className(){return "Agent";}
    virtual void delAgent();
    virtual void transmettre(QList <Agent*> *)= 0;
    int distance(int x1,int x2,int y1,int y2){return (int)(sqrt( ((x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1))));}
    Element* getPompierPlusProche();
};

#endif // AGENT_H
