#include "robot.h"

Robot::Robot(Plateau *plateau):Secours(plateau)
{
    this->vision = 1;
}
void Robot::jouer()
{
    this->plateau->deplacer( this , 1 , 1 );
}
