#include "drone.h"
#include <iostream>

Drone::Drone(Plateau *plateau):Secours(plateau)
{
    this->posXCourante = -2;
    this->posYCourante = -2;
    this->vision = 3;
}

void Drone::jouer()
{



    if(this->getPosX()+this->posXCourante >= 0)
    {
       if( !this->plateau->deplacer(this,this->posXCourante,0) )
        {
            this->posXCourante -= 2;
            this->posYCourante -= 2;
        }
       else
       {
           this->posXCourante = -2;
           this->posYCourante = -2;
       }
    }
    else if(this->getPosY()-1 >= 0)
    {
        this->posXCourante = -2;
        this->posYCourante = -2;
        for(int i = 1;  !this->plateau->deplacer(this,this->plateau->getNBLigne()-this->getPosX()-i,-1); i++);
    }
    else
    {
        this->posXCourante = -2;
        this->posYCourante = -2;
        for(int i = 1; !this->plateau->deplacer(this,this->plateau->getNBLigne()-this->getPosX()-i,this->plateau->getNBColone()-1); i++);
    }
    QList<Agent*> *listDetection = this->plateau->getListDetection();
    //listDetection->clear();
    if(!listDetection->contains(this))
    {
        listDetection->append(this);
        this->plateau->detection(listDetection);
    }
}


void Drone::transmettre(QList<Agent *> *list)
{
    if(!list->contains(this) && !list->isEmpty())
    {
        list->append(this);
        this->plateau->detection(list);
    }
}
