#include "victime.h"
#include "math.h"

void Victime::jouer()
{
    // on cherche le feu le plus proche
    Element* feuPlusProche = this->getFeuPlusProche();

    // on ce deplace le plus loin possible de celui ci
    if(feuPlusProche != NULL)
    {
        int deplacementX = 0, deplacementY = 0;
        if(this->getPosX() < feuPlusProche->getX()) deplacementX = -1;
        if(this->getPosX() > feuPlusProche->getX()) deplacementX = 1;
        if(this->getPosY() > feuPlusProche->getY()) deplacementY = -1;
        if(this->getPosY() > feuPlusProche->getY()) deplacementY = 1;
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
Element* Victime::getFeuPlusProche()
{
    Element** grille = this->plateau->getGrilleVue();
    Element* feuPlusProche = NULL;
    int distance = this->plateau->getNBLigne() + this->plateau->getNBColone();
    for(int i = 0; i < this->plateau->getNBLigne(); i++)
        for(int j = 0; j < this->plateau->getNBColone(); j++)
            if(grille[i][j].getFeu() != NULL)
            {
                if( distance > sqrt( (i * j) + (i * j)) )
                {
                    distance = (int)sqrt( (i * j) + (i * j));
                    feuPlusProche = &grille[i][j];
                }
            }
    return feuPlusProche;
}
