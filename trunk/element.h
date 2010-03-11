#ifndef ELEMENT_H
#define ELEMENT_H
class Element;
#include "feu.h"
#include "agent.h"

class Element
{
private:
    Feu* feu;
    Agent* agent;

public:
    Element();
    char* getContenue();
};

#endif // ELEMENT_H
