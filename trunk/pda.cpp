#include "pda.h"


Element* PDA::getFeuPlusProche()
{
    Element** grille = this->plateau->getGrille();
    Element* feuPlusProche = NULL;
    int distance = this->plateau->getNBLigne() + this->plateau->getNBColone();
    for(int i = -this->vision; i <= this->vision; i++)
    {
        for(int j = -this->vision; j <= this->vision; j++)
        {
            if( i+this->getPosX() >= 0 &&
                j+this->getPosY() >= 0 &&
                i+this->getPosX() < this->plateau->getNBLigne() &&
                j+this->getPosY() < this->plateau->getNBColone())
            {
                if(grille[i+this->getPosX()][j+this->getPosY()].getFeu() != NULL)
                {
                    if( distance > this->distance(this->getPosX(),i+this->getPosX(),this->getPosY(),j+this->getPosY()) )
                    {
                        distance = this->distance(this->getPosX(),i+this->getPosX(),this->getPosY(),j+this->getPosY());
                        feuPlusProche = &grille[i+this->getPosX()][j+this->getPosY()];
                    }
                }
            }
        }
    }

    if(feuPlusProche == NULL)
    {
        grille = this->plateau->getGrilleVue();
        for(int i = 0; i < this->plateau->getNBLigne(); i++)
            for(int j = 0; j < this->plateau->getNBColone(); j++)
                if(grille[i][j].getFeu() != NULL)
                {
                    if( distance > this->distance(this->getPosX(),i+this->getPosX(),this->getPosY(),j+this->getPosY()) )
                    {
                        distance = this->distance(this->getPosX(),i+this->getPosX(),this->getPosY(),j+this->getPosY());
                        feuPlusProche = &grille[i][j];
                    }
                }
    }
    return feuPlusProche;
}
