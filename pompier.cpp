#include "pompier.h"
#include <iostream>
void Pompier::jouer()
{
    QList<Agent*> *listDetection = this->plateau->getListDetection();
    listDetection->clear();
    if(!listDetection->contains(this))
    {
        listDetection->append(this);
        this->plateau->detection(listDetection);
    }

    Element* feuPlusProche = this->getFeuPlusProche();
    if(feuPlusProche != NULL)
    {
        std::cout<<feuPlusProche<<std::endl;
        if(this->distance(this->getPosX(),feuPlusProche->getX(),this->getPosY(),feuPlusProche->getY()) > 1)
        {
            int deplacementX = 0, deplacementY = 0;
            if(this->getPosX() < feuPlusProche->getX() && this->getPosX() > 0) deplacementX = 1;
            if(this->getPosX() > feuPlusProche->getX() && this->getPosX() < this->plateau->getNBLigne() -1) deplacementX = -1;
            if(this->getPosY() < feuPlusProche->getY() && this->getPosY() > 0) deplacementY = 1;
            if(this->getPosY() > feuPlusProche->getY() && this->getPosY() < this->plateau->getNBColone() -1) deplacementY = -1;

            this->plateau->deplacer(this, deplacementX, deplacementY);
        }
        else if( this->distance(this->getPosX(),feuPlusProche->getX(),this->getPosY(),feuPlusProche->getY()) == 1  &&
                 this->plateau->getGrilleVue()[feuPlusProche->getX()][feuPlusProche->getY()+1].getFeu() != NULL &&
                 this->plateau->getVent() == OUEST)
        {
            this->plateau->deplacer(this, 0, 1);
        }
        else if( this->distance(this->getPosX(),feuPlusProche->getX(),this->getPosY(),feuPlusProche->getY()) == 1  &&
                 this->plateau->getGrilleVue()[feuPlusProche->getX()][feuPlusProche->getY()-1].getFeu() != NULL &&
                 this->plateau->getVent() == EST)
        {
            this->plateau->deplacer(this, 0, -1);

        }
        else if( this->distance(this->getPosX(),feuPlusProche->getX(),this->getPosY(),feuPlusProche->getY()) == 1  &&
                 this->plateau->getGrilleVue()[feuPlusProche->getX()+1][feuPlusProche->getY()].getFeu() != NULL &&
                 this->plateau->getVent() == SUD)
        {
            this->plateau->deplacer(this, 1, 0);

        }
        else if( this->distance(this->getPosX(),feuPlusProche->getX(),this->getPosY(),feuPlusProche->getY()) == 1  &&
                 this->plateau->getGrilleVue()[feuPlusProche->getX()-1][feuPlusProche->getY()].getFeu() != NULL &&
                 this->plateau->getVent() == NORD)
        {
            this->plateau->deplacer(this, -1, 0);
        }
        else
        {
            std::cout<<"je t'eteindre sale feu!!!!!"<<std::endl;
            this->plateau->supElement(feuPlusProche->getFeu());
        }
    }

}
