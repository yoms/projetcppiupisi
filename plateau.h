#ifndef PLATEAU_H
#define PLATEAU_H
#include <QList>
class Plateau;
enum Direction { EST, OUEST, NORD, SUD};
#include "element.h"
#include "agent.h"
#include "feu.h"


class Plateau
{
private:
    Element **grille;
    QList<Feu> listFeu;
    QList<Agent> listAgent;
    int nbLigne;
    int nbColone;
    Direction directionVent;
    int forceVent;

public:
    Plateau(int x = 7, int y = 9);
    ~Plateau();
    void jouer();
    bool deplacer(int x, int y);
    
    Element* getElement(int x, int y);
    Element** getGrille() const {return this->grille;}
    int getNBLigne(){return this->nbLigne;}
    int getNBColone(){return this->nbColone;}
    QList<Feu> getListFeu() const {return this->listFeu;}
    QList<Agent> getListAgent() const {return this->listAgent;}
    Direction getVent() const {return this->directionVent;}
};

#endif // PLATEAU_H
