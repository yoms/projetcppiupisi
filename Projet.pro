# -------------------------------------------------
# Project created by QtCreator 2010-03-08T13:40:20
# -------------------------------------------------
QT += core \
    gui
TARGET = Projet
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    plateau.cpp \
    element.cpp \
    agent.cpp \
    feu.cpp \
    mainwindow.cpp \
    robot.cpp \
    capteur.cpp \
    drone.cpp \
    victime.cpp \
    pompier.cpp
HEADERS += plateau.h \
    element.h \
    agent.h \
    feu.h \
    mainwindow.h \
    robot.h \
    secours.h \
    capteur.h \
    drone.h \
    pda.h \
    victime.h \
    pompier.h
FORMS += mainwindow.ui
OTHER_FILES += media/pompier.jpg \
    media/personne.png \
    media/feu.png \
    media/avion.gif \
    media/antenne.jpg
