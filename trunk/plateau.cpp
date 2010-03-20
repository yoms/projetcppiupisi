#include <iostream>
#include <QString>
#include "plateau.h"
#include "robot.h"
#include "capteur.h"
#include "drone.h"
#include "victime.h"
#include "pompier.h"

#define NB_FEU 3

Plateau::Plateau(int x, int y):nbLigne(y), nbColone(x)
{
    //pour les tests...............
    this->forceVent = 1;
    this->directionVent = OUEST;

    //---------------------------------------------------------------
    //Creation de la grille
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

    //---------------------------------------------------------------
    //Creation de la grille vue par les agents
    this->grilleVue = new Element*[this->nbLigne];
    for(int i = 0; i < this->nbLigne; i++)
    {
        this->grilleVue[i] = new Element[this->nbColone];
    }
    for(int i = 0; i < this->nbLigne; i++)
        for(int j = 0; j < this->nbColone; j++)
        {
            this->grilleVue[i][j].setX(i);
            this->grilleVue[i][j].setY(j);
        }

    //---------------------------------------------------------------

    for(int i = 0; i < 3; i++)
    {
        this->listAgent.append(new Robot(this));
    }
    this->listAgent.append(new Drone(this));
    this->listAgent.append(new Victime(this));
    this->listAgent.append(new Pompier(this));
    this->listAgent.append(new Capteur(this));
    this->listAgent.append(new Capteur(this));
    this->grille[0][0].setAgent(this->listAgent[0]);
    this->grille[2][1].setAgent(this->listAgent[1]);
    this->grille[4][2].setAgent(this->listAgent[2]);
    this->grille[3][4].setAgent(this->listAgent[3]);
    this->grille[4][0].setAgent(this->listAgent[4]);
    this->grille[5][5].setAgent(this->listAgent[5]);
    this->grille[2][2].setAgent(this->listAgent[6]);
    this->grille[7][7].setAgent(this->listAgent[7]);


    for(int i = 0; i < NB_FEU; i++)
    {
        this->listFeu.append(Feu(this));
        this->grille[3+i][2].setFeu(&this->listFeu.last());
    }

}

Plateau::~Plateau()
{
    for(int i = 0; i < nbColone; i++ )
    {
        delete[] this->grille[i];
        delete[] this->grilleVue[i];
    }

    delete[] grille;
    delete[] grilleVue;
}

void Plateau::jouer()
{

    for(int i = 0; i < this->nbLigne; i++)
        for(int j = 0; j < this->nbColone; j++)
            this->grilleVue[i][j] = Element(i,j);

    QList<Feu*> tmpFeu;
    for(int i = 0; i < this->listFeu.size(); i++) tmpFeu.append(&listFeu[i]);
    for(int i = 0; i < tmpFeu.size(); i++)
        tmpFeu[i]->jouer();

    QList<Agent*> tmpAgent;
    for(int i = 0; i < this->listAgent.size(); i++) tmpAgent.append(listAgent[i]);
    for(int i = 0; i < tmpAgent.size(); i++)
        tmpAgent[i]->jouer();
}
Element* Plateau::getElement(int x, int y)
{
    return &this->grille[x][y];
}
Element* Plateau::getElementVue(int x, int y)
{
    return &this->grilleVue[x][y];
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
        if(this->grille[agent->getPosX() + x][agent->getPosY() + y].setAgent(agent))
        {
            this->grille[agent->getPosX()- x][agent->getPosY() - y].delAgent();
            return true;
        }
    }
    return false;

}

void Plateau::supElement(Agent * agent)
{
    this->listAgent.removeAt(this->listAgent.indexOf(agent));
    this->grille[agent->getPosX()][agent->getPosY()].delAgent();
    delete agent;
}

void Plateau::supElement(Feu * feu)
{
    for(int i=0;i<this->listFeu.size();i++)
    {
        if(&this->listFeu[i] == feu)
        {
            this->listFeu.removeAt(i);
            this->grille[feu->getPosX()][feu->getPosY()].delFeu();
        }
    }
}

void Plateau::detection(QList<Agent*> *listDetection)
{
    Agent* agent = listDetection->last();
    int x = agent->getPosX();
    int y = agent->getPosY();
    int vision = agent->getVision();

    QList<Agent*> antenne;
    QList<Agent*> drone;
    QList<Agent*> robot;


    //Detection contour elementCourant
    //si antenne disponible => on transmet a antenne
    //sinon on regarde si ya un robot ou un drone
    for(int i=x-vision;i<=x+vision;i++)
    {
        for(int j=y-vision;j<=y+vision;j++)
        {
            if(i>=0 && j>=0 && i<this->nbLigne && j<this->nbColone && (i != x || j != y))
            {
                if(this->getElement(i,j)->getAgent() != NULL)
                {
                    if(QString(this->getElement(i,j)->getContenue()) == QString("Capteur"))
                    {
                        antenne.append(this->getElement(i,j)->getAgent());
                    }
                    else if(QString(this->getElement(i,j)->getContenue()) == QString("Drone"))
                    {
                        drone.append(this->getElement(i,j)->getAgent());
                    }
                    else if(QString(this->getElement(i,j)->getContenue()) == QString("Robot"))
                    {
                        robot.append(this->getElement(i,j)->getAgent());
                    }
                }
            }
        }
    }
    bool finOption = false;
    //transmission a un drone
    //sinon transmission a un robot
    if(!antenne.empty())
        antenne.last()->transmettre(listDetection);
    else
    {
        if(!drone.empty())
            for(int i = 0; i < drone.size(); i++)
            {
                if(!listDetection->contains(drone[i]))
                {
                    finOption = finOption || true;
                    drone[i]->transmettre(listDetection);
                }
            }
        if(!robot.empty())
            for(int i = 0; i < robot.size(); i++)
            {
                if(!listDetection->contains(robot[i]))
                {
                    finOption = finOption || true;
                    robot[i]->transmettre(listDetection);
                }
            }
    }

}
