#include "robot.h"

Robot::Robot(Plateau *plateau):Secours(plateau)
{
}
void Robot::jouer()
{
    this->plateau->deplacer( this , 1 , 1 );
}
