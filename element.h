#ifndef ELEMENT_H
#define ELEMENT_H
class Element;
#include "feu.h"
#include "agent.h"

class Element
{
private:
    Feu* feu;
    Agent* agent;
    int x, y;
    bool eteind;
public:
    Element(int x = 0, int y = 0);
    char* getContenue();
    int getX(){return x;}
    int getY(){return y;}
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    bool setAgent(Agent*);
    bool setFeu(Feu*);
    Agent* getAgent(){return agent;}
    Feu* getFeu(){return feu;}
    void delAgent();
    void delFeu();
};

#endif // ELEMENT_H
