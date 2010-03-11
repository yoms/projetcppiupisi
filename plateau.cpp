#include "plateau.h"
#define NB_FEU 3

Plateau::Plateau(int x, int y):nbLigne(y), nbColone(x)
{
//pour les tests...............
    this->forceVent = 1;
    this->directionVent = EST;
//.............................
    this->grille = new Element*[this->nbLigne];
    for(int i = 0; i < this->nbLigne; i++)
    {
        this->grille[i] = new Element[this->nbColone];
    }

    for(int i = 0; i < 3; i++)
    {
        this->listAgent.append(Agent(this));
    }
    for(int i = 0; i < NB_FEU; i++)
    {
        this->listFeu.append(Feu(this));
    }

}

Plateau::~Plateau()
{
    for(int i = 0; i < nbColone; i++ )
        delete[] this->grille[i];
    delete[] grille;
}

void Plateau::jouer()
{
    for(int i = 0; i < this->listFeu.size(); i++)
        listFeu[i].jouer();
    for(int i = 0; i < this->listAgent.size(); i++)
        listAgent[i].jouer();
}
Element* Plateau::getElement(int x, int y)
{
    return &this->grille[x][y];
}
