#ifndef PLATEAU_H
#define PLATEAU_H
#include <QList>
#include "math.h"
class Plateau;
enum Direction { EST, OUEST, NORD, SUD};
#include "element.h"
#include "agent.h"
#include "feu.h"

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
    static int distance(int x1,int x2,int y1,int y2){return (int)(sqrt( ((x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1))));}
    static int distance(Agent* agent1,Agent* agent2);

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
