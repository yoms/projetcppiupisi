#include <iostream>
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
    for(int i = 0; i < this->nbLigne; i++)
        for(int j = 0; j < this->nbColone; j++)
        {
            this->grille[i][j].setX(i);
            this->grille[i][j].setY(j);
        }
    for(int i = 0; i < 3; i++)
    {
        this->listAgent.append(Agent(this));
    }
    this->grille[0][0].setAgent(&this->listAgent[0]);
    this->grille[0][1].setAgent(&this->listAgent[1]);
    this->grille[0][2].setAgent(&this->listAgent[2]);
    for(int i = 0; i < NB_FEU; i++)
    {
        this->listFeu.append(Feu(this));
    }
    this->grille[0][0].setFeu(this);

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
bool Plateau::deplacer( Agent* agent, int x, int y )
{

    if( x + agent->getPosX() < this->nbLigne &&
        y + agent->getPosY() < this->nbColone)
    {
        this->grille[agent->getPosX()][agent->getPosY()].delAgent();
        this->grille[agent->getPosX() + x][agent->getPosY() + y].setAgent(agent);
        return true;
    }
    return false;

}

bool deplacer( Feu* );
