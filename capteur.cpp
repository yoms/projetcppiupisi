#include "capteur.h"

Capteur::Capteur(Plateau *plateau):Secours(plateau)
{
    this->vision = 3;
}

void Capteur::jouer()
{
    for(int j = -vision; j < vision; j++)
    {
        for(int k = -vision; k < vision; k++)
        {
            if(    (this->getPosX()+j < this->plateau->getNBLigne() )
                && (this->getPosY()+k < this->plateau->getNBColone() )
                && (0 <  this->getPosX()+j )
                && (0 <  this->getPosY()+k )
                )
            this->plateau->getGrilleVue()[this->getPosX()+j][this->getPosY()+k] = this->plateau->getGrille()[this->getPosX()+j][this->getPosY()+k];
        }
    }
}

void  Capteur::transmettre(QList<Agent*>* list)
{
    for(int i = 0; i < list->size(); i++)
    {
        Agent* agent = list->at(i);
        int vision = agent->getVision();
        for(int j = -vision; j < vision; j++)
        {
            for(int k = -vision; k < vision; k++)
            {
                if(    (agent->getPosX()+j < this->plateau->getNBLigne() )
                    && (agent->getPosY()+k < this->plateau->getNBColone() )
                    && (0 <=  agent->getPosX()+j )
                    && (0 <=  agent->getPosY()+k )
                    )
                this->plateau->getGrilleVue()[agent->getPosX()+j][agent->getPosY()+k] = this->plateau->getGrille()[agent->getPosX()+j][agent->getPosY()+k];
            }
        }
    }
    this->plateau->getListDetection()->clear();
}
