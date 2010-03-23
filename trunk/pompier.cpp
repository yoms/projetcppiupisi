#include "pompier.h"
#include <iostream>
void Pompier::jouer()
{
    QList<Agent*> *listDetection = this->plateau->getListDetection();
    //listDetection->clear();
    if(!listDetection->contains(this))
    {
        listDetection->append(this);
        this->plateau->detection(listDetection);
    }

    Element* feuPlusProche = this->getFeuPlusProche();
    if(feuPlusProche != NULL)
    {
        if(this->distance(this->getPosX(),feuPlusProche->getX(),this->getPosY(),feuPlusProche->getY()) > 1)
        {
            int deplacementX = 0, deplacementY = 0;
            if(this->getPosX() < feuPlusProche->getX() && this->getPosX() < this->plateau->getNBLigne() -1) deplacementX = 1;
            if(this->getPosX() > feuPlusProche->getX() && this->getPosX() > 0) deplacementX = -1;
            if(this->getPosY() < feuPlusProche->getY() && this->getPosY() < this->plateau->getNBColone() -1) deplacementY = 1;
            if(this->getPosY() > feuPlusProche->getY() && this->getPosY() > 0) deplacementY = -1;

            this->plateau->deplacer(this, deplacementX, deplacementY);
        }
        else
        {
            this->plateau->supElement(feuPlusProche->getFeu());
        }
    }

}
