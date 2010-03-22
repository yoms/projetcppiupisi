#include "robot.h"

Robot::Robot(Plateau *plateau):Secours(plateau)
{
    this->vision = 2;
}
void Robot::jouer()
{
    this->plateau->deplacer( this , 1 , 1 );
    QList<Agent*> *listDetection = this->plateau->getListDetection();
    listDetection->clear();
    if(!listDetection->contains(this))
    {
        listDetection->append(this);
        this->plateau->detection(listDetection);
    }
}
void Robot::transmettre(QList<Agent *> *list)
{
    if(!list->contains(this))
    {
        list->append(this);
        this->plateau->detection(list);
    }
}
