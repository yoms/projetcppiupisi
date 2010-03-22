#include "victime.h"

void Victime::jouer()
{
    if(this->etat == VALIDE)
    {
        // on cherche le feu le plus proche
        Element* feuPlusProche = this->getFeuPlusProche();

        // on ce deplace le plus loin possible de celui ci
        if(feuPlusProche != NULL)
        {
            int deplacementX = 0, deplacementY = 0;
            if(this->getPosX() < feuPlusProche->getX() && this->getPosX() > 0) deplacementX = -1;
            if(this->getPosX() > feuPlusProche->getX() && this->getPosX() < this->plateau->getNBLigne() -1) deplacementX = 1;
            if(this->getPosY() < feuPlusProche->getY() && this->getPosY() > 0) deplacementY = -1;
            if(this->getPosY() > feuPlusProche->getY() && this->getPosY() < this->plateau->getNBColone() -1) deplacementY = 1;
            this->plateau->deplacer(this, deplacementX, deplacementY);
        }




        QList<Agent*> *listDetection = this->plateau->getListDetection();
        listDetection->clear();
        if(!listDetection->contains(this))
        {
            listDetection->append(this);
            this->plateau->detection(listDetection);
        }
    }
}
