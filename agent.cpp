#include "agent.h"
#include <iostream>

Agent::Agent(Plateau *plateau):plateau(plateau)
{
    this->vision = 1;
}


int Agent::getPosX()
{
    return this->element->getX();
}
int Agent::getPosY()
{
    return this->element->getY();
}
void Agent::delAgent()
{
    this->plateau->supElement(this);
}

Element* Agent::getPompierPlusProche()
{
    Element** grille = this->plateau->getGrille();
    Element* capteurPlusProche = NULL;
    int distance = this->plateau->getNBLigne() + this->plateau->getNBColone();

    for(int i=0;i<this->plateau->getNBLigne();i++)
    {
        for(int j=0;j<this->plateau->getNBColone();j++)
        {            
            if(QString(this->plateau->getElement(i,j)->getContenue())==QString("Pompier"))
            {                
                if((i<(this->getPosX()-this->vision) || i>(this->getPosX()+this->vision)) && (j<(this->getPosY()-this->vision) || j>(this->getPosY()+this->vision)))
                {
                    if(distance > Plateau::distance(this->getPosX(),i,this->getPosY(),j))
                    {
                        distance = Plateau::distance(this->getPosX(),i,this->getPosY(),j);
                        std::cout<<"pompier : "<<i<<'-'<<j<<"   distance = "<<distance<<std::endl;
                        capteurPlusProche = &grille[i][j];
                    }
                }
            }
        }
    }
    return capteurPlusProche;
}
