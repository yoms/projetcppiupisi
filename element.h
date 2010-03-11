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
public:
    Element(int x = 0, int y = 0);
    char* getContenue();
    int getX(){return x;}
    int getY(){return y;}
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    bool setAgent(Agent*);
    Feu* setFeu(Plateau* plateau);
    void delAgent();
    void delFeu();
};

#endif // ELEMENT_H
