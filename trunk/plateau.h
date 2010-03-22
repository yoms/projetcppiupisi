#ifndef PLATEAU_H
#define PLATEAU_H
#include <QList>
class Plateau;
enum Direction { EST, OUEST, NORD, SUD};
#include "element.h"
#include "agent.h"
#include "feu.h"
struct Point{
    int x;
    int y;
};

class Plateau
{
private:
    Element **grille;
    Element **grilleVue;
    QList<Feu> listFeu;
    QList<Agent*> listAgent;
    QList<Agent*> listDetection;
    int nbLigne;
    int nbColone;
    Direction directionVent;
    int forceVent;

public:
    Plateau(int x = 7, int y = 9);
    ~Plateau();
    void jouer();
    bool deplacer( Agent*, int x, int y );
    bool deplacer( Feu* );

    Element* getElement(int x, int y);
    Element* getElementVue(int x, int y);
    Element** getGrille() const {return this->grille;}
    Element** getGrilleVue() const {return this->grilleVue;}
    QList<Agent*> *getListDetection(){return &this->listDetection;}
    int getNBLigne(){return this->nbLigne;}
    int getNBColone(){return this->nbColone;}
    QList<Feu> getListFeu() const {return this->listFeu;}
    QList<Agent*> getListAgent() const {return this->listAgent;}
    Direction getVent() const {return this->directionVent;}

    void supElement(Agent * agent);
    void supElement(Feu * feu);

    void detection(QList<Agent *>*);
};

#endif // PLATEAU_H
