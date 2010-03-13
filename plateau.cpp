#include <iostream>
#include "plateau.h"
#define NB_FEU 1

Plateau::Plateau(int x, int y):nbLigne(y), nbColone(x)
{
//pour les tests...............
    this->forceVent = 1;
    this->directionVent = OUEST;
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
    this->grille[3][4].setFeu(&this->listFeu[0]);

}

Plateau::~Plateau()
{
    for(int i = 0; i < nbColone; i++ )
        delete[] this->grille[i];
    delete[] grille;
}

void Plateau::jouer()
{
    QList<Feu*> tmp;
    for(int i = 0; i < this->listFeu.size(); i++) tmp.append(&listFeu[i]);
    std::cout<<"taille du temp : "<<tmp.size()<<std::endl;
    for(int i = 0; i < tmp.size(); i++)
        tmp[i]->jouer();
    for(int i = 0; i < this->listAgent.size(); i++)
        listAgent[i].jouer();
}
Element* Plateau::getElement(int x, int y)
{
    return &this->grille[x][y];
}

bool Plateau::deplacer(Feu * feu)
{
    switch(this->directionVent)
    {
        case NORD:
        {
            for(int i=1;i<=this->forceVent;i++)
            {                
                if(feu->getPosX()-i >= 0)
                {
                    this->listFeu.append(Feu(this));
                    this->grille[feu->getPosX()-i][feu->getPosY()].setFeu(&this->listFeu.last());                    
                }
            }
        }
        break;

        case EST:
        {
            for(int i=1;i<=this->forceVent;i++)
            {
                if(feu->getPosY()+i <= this->nbColone)
                {
                    this->listFeu.append(Feu(this));
                    this->grille[feu->getPosX()][feu->getPosY()+i].setFeu(&this->listFeu.last());
                }
            }
        }
        break;

        case SUD:
        {
            for(int i=1;i<=this->forceVent;i++)
            {
                if(feu->getPosX()+i <= this->nbLigne)
                {
                    this->listFeu.append(Feu(this));
                    this->grille[feu->getPosX()+i][feu->getPosY()].setFeu(&this->listFeu.last());
                }
            }
        }
        break;

        case OUEST:       
        {
            for(int i=1;i<=this->forceVent;i++)
            {
                if(feu->getPosY()-i >= 0)
                {
                    this->listFeu.append(Feu(this));
                    this->grille[feu->getPosX()][feu->getPosY()-i].setFeu(&this->listFeu.last());
                }
            }
        }
        break;
    }
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

