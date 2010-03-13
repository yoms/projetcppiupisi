#include "element.h"
#include <iostream>

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

bool Element::setFeu(Feu *feu)
{
    std::cout<<feu<<std::endl<<"  -  "<<this->feu<<std::endl;

    if((feu != NULL) && (this->feu == NULL))
    {
        this->feu = feu;
        this->feu->lier(this);
        if(this->agent != NULL)
        {
            this->agent->delAgent();
        }
        return true;
    }
    return false;
}

void Element::delAgent()
{
    this->agent = NULL;
}

void Element::delFeu()
{
    this->feu = NULL;
}
