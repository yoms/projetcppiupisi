#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <unistd.h>
#include <QTimer>
#define IMAGE_FEU "./media/feu.png"
#define IMAGE_CAPTEUR "./media/antenne.jpg"
#define IMAGE_DRONE "./media/avion.gif"
#define IMAGE_VICTIME "./media/personne.png"
#define IMAGE_POMPIER "./media/pompier.jpg"
#define IMAGE_ROBOT "./media/robot.png"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->plateau = new Plateau(10,10);

    //---------------------------------------------------------------
    //Creation de la grille
    this->element = new QLabel*[plateau->getNBLigne()];
    for(int i = 0; i < plateau->getNBLigne(); i++)
    {
        this->element[i] = new QLabel[this->plateau->getNBColone()];
    }
    for(int i =0; i <this->plateau->getNBLigne(); i++)
        for(int j = 0; j < this->plateau->getNBColone(); j++)
        {
            this->ui->gridLayout->addWidget(&this->element[i][j], i, j);
            this->element[i][j].resize(50,50);
            this->element[i][j].setMaximumSize(50,50);
            this->element[i][j].setMinimumSize(50,50);
        }


    //---------------------------------------------------------------
    //Creation de la grille Vue par les Agents
    this->elementVue = new QLabel*[plateau->getNBLigne()];
    for(int i = 0; i < plateau->getNBLigne(); i++)
    {
        this->elementVue[i] = new QLabel[this->plateau->getNBColone()];
    }
    for(int i =0; i <this->plateau->getNBLigne(); i++)
        for(int j = 0; j < this->plateau->getNBColone(); j++)
        {
            this->ui->gridLayout_2->addWidget(&this->elementVue[i][j], i, j);
            this->elementVue[i][j].resize(50,50);
            this->elementVue[i][j].setMaximumSize(50,50);
            this->elementVue[i][j].setMinimumSize(50,50);
        }


    this->setGrille();
    /*QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(jouer()));
    timer->start(200);*/
    connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(jouer()));


}

MainWindow::~MainWindow()
{
    for(int i = 0; i < this->plateau->getNBLigne(); i++)
    {
        delete[] this->element[i];
        delete[] this->elementVue[i];
    }
    delete[] this->element;
    delete[] this->elementVue;
    delete ui;
}

void MainWindow::jouer()
{
    this->plateau->jouer();   
    this->setGrille();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void MainWindow::setGrille()
{
    for(int i = 0; i < this->plateau->getNBLigne(); i++)
        for(int j = 0; j < this->plateau->getNBColone(); j++)
        {
            this->element[i][j].clear();
            if(QString(this->plateau->getElement(i,j)->getContenue()) == QString("Feu"))
            {
                this->element[i][j].setPixmap(QPixmap(IMAGE_FEU));
            }
            else if(QString(this->plateau->getElement(i,j)->getContenue()) == QString("Agent"))
            {
                this->element[i][j].setPixmap(QPixmap(IMAGE_POMPIER));
            }
            else if(QString(this->plateau->getElement(i,j)->getContenue()) == QString("Pompier"))
            {
                this->element[i][j].setPixmap(QPixmap(IMAGE_POMPIER));
            }
            else if(QString(this->plateau->getElement(i,j)->getContenue()) == QString("Robot"))
            {
                this->element[i][j].setPixmap(QPixmap(IMAGE_ROBOT));
            }
            else if(QString(this->plateau->getElement(i,j)->getContenue()) == QString("Drone"))
            {
                this->element[i][j].setPixmap(QPixmap(IMAGE_DRONE));
            }
            else if(QString(this->plateau->getElement(i,j)->getContenue()) == QString("Capteur"))
            {
                this->element[i][j].setPixmap(QPixmap(IMAGE_CAPTEUR));
            }
            else if(QString(this->plateau->getElement(i,j)->getContenue()) == QString("Victime"))
            {
                this->element[i][j].setPixmap(QPixmap(IMAGE_VICTIME));
            }
            else this->element[i][j].setText(QString(i+48)+QString("-")+QString(j+48));

        }
    for(int i = 0; i < this->plateau->getNBLigne(); i++)
        for(int j = 0; j < this->plateau->getNBColone(); j++)
        {
            this->elementVue[i][j].clear();
            if(QString(this->plateau->getElementVue(i,j)->getContenue()) == QString("Feu"))
            {
                this->elementVue[i][j].setPixmap(QPixmap(IMAGE_FEU));
            }
            else if(QString(this->plateau->getElementVue(i,j)->getContenue()) == QString("Agent"))
            {
                this->elementVue[i][j].setPixmap(QPixmap(IMAGE_POMPIER));
            }
            else if(QString(this->plateau->getElementVue(i,j)->getContenue()) == QString("Pompier"))
            {
                this->elementVue[i][j].setPixmap(QPixmap(IMAGE_POMPIER));
            }
            else if(QString(this->plateau->getElementVue(i,j)->getContenue()) == QString("Robot"))
            {
                this->elementVue[i][j].setPixmap(QPixmap(IMAGE_ROBOT));
            }
            else if(QString(this->plateau->getElementVue(i,j)->getContenue()) == QString("Drone"))
            {
                this->elementVue[i][j].setPixmap(QPixmap(IMAGE_DRONE));
            }
            else if(QString(this->plateau->getElementVue(i,j)->getContenue()) == QString("Capteur"))
            {
                this->elementVue[i][j].setPixmap(QPixmap(IMAGE_CAPTEUR));
            }
            else if(QString(this->plateau->getElementVue(i,j)->getContenue()) == QString("Victime"))
            {
                this->elementVue[i][j].setPixmap(QPixmap(IMAGE_VICTIME));
            }
            else this->elementVue[i][j].setText(QString(i+48)+QString("-")+QString(j+48));

        }
}
