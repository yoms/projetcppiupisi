#include "drone.h"

Drone::Drone(Plateau *plateau):Secours(plateau)
{
}

void Drone::jouer()
{
    if(this->getPosX()-1 > 0)this->plateau->deplacer(this,-2,0);
    else
    {
        if(this->getPosY()-1 > 0)this->plateau->deplacer(this,this->plateau->getNBLigne()-1,-1);
        else this->plateau->deplacer(this,this->plateau->getNBLigne()-1,this->plateau->getNBColone()-1);
    }

}

