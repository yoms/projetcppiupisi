#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QLabel>
#include <QtCore/QObject>
#include "plateau.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
private slots:
    void jouer();
private:
    void setGrille();

    Ui::MainWindow *ui;
    QLabel** element;
    QLabel** elementVue;
    Plateau* plateau;
};

#endif // MAINWINDOW_H
