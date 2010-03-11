#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->plateau = new Plateau;
    this->element = new QLabel*[plateau->getNBLigne()];
    for(int i = 0; i < plateau->getNBLigne(); i++)
    {
        this->element[i] = new QLabel[this->plateau->getNBColone()];
    }
    for(int i =0; i <this->plateau->getNBLigne(); i++)
        for(int j = 0; j < this->plateau->getNBColone(); j++)
        {
            this->ui->gridLayout->addWidget(&this->element[i][j], i, j);
            this->element[i][j].setText("coucou");
        }
    connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(jouer()));

}

MainWindow::~MainWindow()
{
    for(int i = 0; i < this->plateau->getNBLigne(); i++)
        delete[] this->element[i];
    delete[] this->element;
    delete ui;
}

void MainWindow::jouer()
{
    this->plateau->jouer();
    setGrille();
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
            this->element[i][j].setText(this->plateau->getElement(i,j)->getContenue());
}
