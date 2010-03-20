#ifndef DRONE_H
#define DRONE_H
#include "secours.h"

class Drone : public Secours
{
private:
    int posXCourante;
    int posYCourante;
public:
    Drone(Plateau* plateau);
    void jouer();
    void personneBlesser(int x,int y ){}
    void feu(int x,int y ){}
    char* className(){ return "Drone"; }
};

#endif // DRONE_H
