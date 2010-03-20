#include "drone.h"
#include <iostream>

Drone::Drone(Plateau *plateau):Secours(plateau)
{
    this->posXCourante = -2;
    this->posYCourante = -2;
    this->vision = 2;
}

void Drone::jouer()
{
    QList<Agent*> *listDetection = new QList<Agent*>;

    std::cout<<"Pos X :"<<this->getPosX()<<std::endl;
    std::cout<<"Pos Y :"<<this->getPosY()<<std::endl;
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
        for(int i = 1;  !this->plateau->deplacer(this,this->plateau->getNBLigne()-this->getPosX()-i,-1); i++);
    }
    else
    {
        this->plateau->deplacer(this,this->plateau->getNBLigne()-this->getPosX()-1,this->plateau->getNBColone()-1);
        std::cout<<"coucou3"<<std::endl;
    }
    //this->plateau->detection(listDetection);
}

