#ifndef ROBOT_H
#define ROBOT_H
#include "secours.h"
#include "plateau.h"
class Robot : public Secours
{
public:
    Robot(Plateau* plateau);
    void jouer();
    void personneBlesser(int x,int y ){}
    void feu(int x,int y ){}
    char* className(){ return "Robot"; }
};

#endif // ROBOT_H
