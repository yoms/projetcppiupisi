#include <iostream>
#include "plateau.h"
#include "robot.h"
#include "capteur.h"
#include "drone.h"
#include "victime.h"
#include "pompier.h"

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
        this->listAgent.append(new Robot(this));
    }
    this->listAgent.append(new Capteur(this));
    this->listAgent.append(new Drone(this));
    this->listAgent.append(new Victime(this));
    this->listAgent.append(new Pompier(this));
    this->grille[0][0].setAgent(this->listAgent[0]);
    this->grille[0][1].setAgent(this->listAgent[1]);
    this->grille[0][2].setAgent(this->listAgent[2]);
    this->grille[4][4].setAgent(this->listAgent[3]);
    this->grille[4][5].setAgent(this->listAgent[4]);
    this->grille[5][5].setAgent(this->listAgent[5]);
    this->grille[2][2].setAgent(this->listAgent[6]);
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
    QList<Feu*> tmpFeu;
    for(int i = 0; i < this->listFeu.size(); i++) tmpFeu.append(&listFeu[i]);
    QList<Agent*> tmpAgent;
    for(int i = 0; i < this->listAgent.size(); i++) tmpAgent.append(listAgent[i]);
    for(int i = 0; i < tmpFeu.size(); i++)
        tmpFeu[i]->jouer();
    for(int i = 0; i < tmpAgent.size(); i++)
        tmpAgent[i]->jouer();
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
                    Feu feuBuff(this);
                    if(this->grille[feu->getPosX()-i][feu->getPosY()].setFeu(&feuBuff))
                        this->listFeu.append(feuBuff);
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
                    Feu feuBuff(this);
                    if(this->grille[feu->getPosX()][feu->getPosY()+i].setFeu(&feuBuff))
                        this->listFeu.append(Feu(this));
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
                    Feu feuBuff(this);
                    if(this->grille[feu->getPosX()+i][feu->getPosY()].setFeu(&feuBuff))
                        this->listFeu.append(feuBuff);
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
                    Feu feuBuff(this);
                    if(this->grille[feu->getPosX()][feu->getPosY()-i].setFeu(&feuBuff))
                        this->listFeu.append(feuBuff);
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

void Plateau::supElement(Agent * agent)
{
    for(int i=0;i<this->listAgent.size();i++)
    {
        if(this->listAgent[i] == agent)
        {            
            delete this->listAgent[i];
            this->listAgent.removeAt(i);           
        }
    }
}

void Plateau::supElement(Feu * feu)
{
    for(int i=0;i<this->listFeu.size();i++)
    {
        if(&this->listFeu[i] == feu)
        {
            this->listFeu.removeAt(i);
        }
    }
}
