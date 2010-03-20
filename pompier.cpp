#include "pompier.h"

void Pompier::jouer()
{
    QList<Agent*> *listDetection = this->plateau->getListDetection();
    listDetection->clear();
    if(!listDetection->contains(this))
    {
        listDetection->append(this);
        this->plateau->detection(listDetection);
    }
}
