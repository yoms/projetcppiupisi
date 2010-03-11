#include "element.h"

Element::Element(int x, int y):x(x),y(y)
{
    this->agent = NULL;
    this->feu = NULL;
}
char* Element::getContenue(){
    if(feu != NULL)return feu->className();
    else if(agent != NULL) return agent->className();
    return "";
}

bool Element::setAgent(Agent* agent)
{
    if(agent != NULL && this->agent == NULL)
    {
        this->agent = agent;
        this->agent->lier(this);
        return true;
    }
    return false;
}

Feu* Element::setFeu(Plateau *plateau)
{
    this->feu = new Feu(plateau);
    return this->feu;
}

void Element::delAgent()
{
    this->agent = NULL;
}

void Element::delFeu()
{
    this->feu = NULL;
}
