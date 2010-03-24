#include "robot.h"
#include<iostream>

Robot::Robot(Plateau *plateau):Secours(plateau)
{
    this->vision = 2;
}
void Robot::jouer()
{    
    // on cherche le capteur le plus proche
    Element* capteurPlusProche = this->getCapteurPlusProche();
    if(capteurPlusProche != NULL)
    {
        Element* pompierPlusProche = capteurPlusProche->getAgent()->getPompierPlusProche();
        if(pompierPlusProche != NULL)
        {
            std::cout<<"robot : "<<this->getPosX()<<'-'<<this->getPosY()<<std::endl;
            std::cout<<capteurPlusProche->getContenue()<<" ("<<capteurPlusProche->getX()<<'-'<<capteurPlusProche->getY()<<")"<<std::endl;
            std::cout<<" ====> "<<pompierPlusProche->getContenue()<<" ("<<pompierPlusProche->getX()<<"-"<<pompierPlusProche->getY()<<")"<<std::endl;
        }
    }

    QList<Agent*> *listDetection = this->plateau->getListDetection();
    //listDetection->clear();
    if(!listDetection->contains(this))
    {
        listDetection->append(this);
        this->plateau->detection(listDetection);
    }
}

void Robot::transmettre(QList<Agent *> *list)
{
    if(!list->contains(this) && !list->isEmpty())
    {
        list->append(this);
        this->plateau->detection(list);
    }
}
