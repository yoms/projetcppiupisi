#include <iostream>
#include <QString>
#include "plateau.h"
#include "robot.h"
#include "capteur.h"
#include "drone.h"
#include "victime.h"
#include "pompier.h"

#define NB_FEU 3
#define NB_DRONE 1
#define NB_ROBOT 3
#define NB_VICTIME 3
#define NB_POMPIER 3
#define NB_CAPTEUR 3

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

    qsrand((int)this->grille);
    for(int i = 0; i < NB_FEU; i++)
    {
        this->listFeu.append(Feu(this));
        while(!this->grille[qrand()%this->nbLigne][qrand()%this->nbColone].setFeu(&this->listFeu.last()));
    }
    for(int i = 0; i < NB_DRONE; i++)
    {
        this->listAgent.append(new Drone(this));
        while(!this->grille[qrand()%this->nbLigne][qrand()%this->nbColone].setAgent(this->listAgent.last()));
    }
    for(int i = 0; i < NB_CAPTEUR; i++)
    {
        this->listAgent.append(new Capteur(this));
        while(!this->grille[qrand()%this->nbLigne][qrand()%this->nbColone].setAgent(this->listAgent.last()));
    }
    for(int i = 0; i < NB_ROBOT; i++)
    {
        this->listAgent.append(new Robot(this));
        while(!this->grille[qrand()%this->nbLigne][qrand()%this->nbColone].setAgent(this->listAgent.last()));
    }
    for(int i = 0; i < NB_VICTIME; i++)
    {
        this->listAgent.append(new Victime(this/*, qrand()%2 == 0? VALIDE:BLESSER*/));
        while(!this->grille[qrand()%this->nbLigne][qrand()%this->nbColone].setAgent(this->listAgent.last()));
    }
    for(int i = 0; i < NB_POMPIER; i++)
    {
        this->listAgent.append(new Pompier(this));
        while(!this->grille[qrand()%this->nbLigne][qrand()%this->nbColone].setAgent(this->listAgent.last()));
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
        listFeu[i].jouer();

    for(int i = 0; i < listAgent.size(); i++)
        listAgent[i]->jouer();
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
                    this->listFeu.append(Feu(this));
                    if(this->grille[feu->getPosX()-i][feu->getPosY()].setFeu(&this->listFeu.last()))this->listFeu.removeLast();
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
                    if(this->grille[feu->getPosX()][feu->getPosY()+i].setFeu(&this->listFeu.last()))this->listFeu.removeLast();
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
                    if(this->grille[feu->getPosX()+i][feu->getPosY()].setFeu(&this->listFeu.last()))this->listFeu.removeLast();
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
                    if(!this->grille[feu->getPosX()][feu->getPosY()-i].setFeu(&this->listFeu.last()))this->listFeu.removeLast();
                }
            }
        }
        break;
    }
}

bool Plateau::deplacer( Agent* agent, int x, int y )
{

    if( x + agent->getPosX() >= 0            &&
        y + agent->getPosY() >= 0            &&
        x + agent->getPosX() < this->nbLigne &&
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
    if(agent != NULL)
    {
        this->listAgent.removeAt(this->listAgent.indexOf(agent));
        this->grille[agent->getPosX()][agent->getPosY()].delAgent();
        delete agent;
    }
}

void Plateau::supElement(Feu * feu)
{
    if( feu != NULL )
        std::cout<<listFeu.size()<<std::endl;
        for(int i=0;i<this->listFeu.size();i++)
        {
            if(&this->listFeu[i] == feu)
            {
                this->grille[feu->getPosX()][feu->getPosY()].delFeu();
                this->listFeu.removeAt(i);
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
    for(int i = 0; i < listDetection->size(); i++)
        std::cout<< listDetection->at(i)->className() <<" : "<<listDetection->at(i)<<" size: "<<i <<std::endl;
    //Detection contour elementCourant
    //si antenne disponible => on transmet a antenne
    //sinon on regarde si ya un robot ou un drone
    QString string1, string2;
    for(int i=x-vision;i<=x+vision;i++)
    {
        for(int j=y-vision;j<=y+vision;j++)
        {
            if(i>=0 && j>=0 && i<this->nbLigne && j<this->nbColone && (i != x || j != y))
            {
                if(this->getElement(i,j)->getAgent() != NULL)
                {
                    if((string1 = this->getElement(i,j)->getContenue()) == (string2 = "Capteur"))
                    {
                        antenne.append(this->getElement(i,j)->getAgent());
                    }
                    else if((string1 = this->getElement(i,j)->getContenue()) == (string2 = "Drone"))
                    {
                        drone.append(this->getElement(i,j)->getAgent());
                    }
                    else if((string1 = this->getElement(i,j)->getContenue()) == (string2 = "Robot"))
                    {
                        robot.append(this->getElement(i,j)->getAgent());
                    }
                }
            }
        }
    }
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
                        drone[i]->transmettre(listDetection);
                    }
             }
        else if(!robot.empty())
            for(int i = 0; i < robot.size(); i++)
            {
                    if(!listDetection->contains(robot[i]))
                    {
                        robot[i]->transmettre(listDetection);
                    }
             }
        }

}
