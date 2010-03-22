#############################################################################
# Makefile for building: Projet
# Generated by qmake (2.01a) (Qt 4.5.2) on: lun. mars 22 21:46:16 2010
# Project:  Projet.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile Projet.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		plateau.cpp \
		element.cpp \
		agent.cpp \
		feu.cpp \
		mainwindow.cpp \
		robot.cpp \
		capteur.cpp \
		drone.cpp \
		victime.cpp \
		pompier.cpp \
		pda.cpp moc_mainwindow.cpp
OBJECTS       = main.o \
		plateau.o \
		element.o \
		agent.o \
		feu.o \
		mainwindow.o \
		robot.o \
		capteur.o \
		drone.o \
		victime.o \
		pompier.o \
		pda.o \
		moc_mainwindow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Projet.pro
QMAKE_TARGET  = Projet
DESTDIR       = 
TARGET        = Projet

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Projet.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile Projet.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile Projet.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Projet1.0.0 || $(MKDIR) .tmp/Projet1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Projet1.0.0/ && $(COPY_FILE) --parents plateau.h element.h agent.h feu.h mainwindow.h robot.h secours.h capteur.h drone.h pda.h victime.h pompier.h .tmp/Projet1.0.0/ && $(COPY_FILE) --parents main.cpp plateau.cpp element.cpp agent.cpp feu.cpp mainwindow.cpp robot.cpp capteur.cpp drone.cpp victime.cpp pompier.cpp pda.cpp .tmp/Projet1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/Projet1.0.0/ && (cd `dirname .tmp/Projet1.0.0` && $(TAR) Projet1.0.0.tar Projet1.0.0 && $(COMPRESS) Projet1.0.0.tar) && $(MOVE) `dirname .tmp/Projet1.0.0`/Projet1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Projet1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: plateau.h \
		element.h \
		feu.h \
		agent.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		plateau.h \
		element.h \
		feu.h \
		agent.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

plateau.o: plateau.cpp plateau.h \
		element.h \
		feu.h \
		agent.h \
		robot.h \
		secours.h \
		capteur.h \
		drone.h \
		victime.h \
		pda.h \
		pompier.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o plateau.o plateau.cpp

element.o: element.cpp element.h \
		feu.h \
		plateau.h \
		agent.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o element.o element.cpp

agent.o: agent.cpp agent.h \
		plateau.h \
		element.h \
		feu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o agent.o agent.cpp

feu.o: feu.cpp feu.h \
		plateau.h \
		element.h \
		agent.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o feu.o feu.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		plateau.h \
		element.h \
		feu.h \
		agent.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

robot.o: robot.cpp robot.h \
		secours.h \
		agent.h \
		plateau.h \
		element.h \
		feu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o robot.o robot.cpp

capteur.o: capteur.cpp capteur.h \
		secours.h \
		agent.h \
		plateau.h \
		element.h \
		feu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o capteur.o capteur.cpp

drone.o: drone.cpp drone.h \
		secours.h \
		agent.h \
		plateau.h \
		element.h \
		feu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o drone.o drone.cpp

victime.o: victime.cpp victime.h \
		pda.h \
		agent.h \
		plateau.h \
		element.h \
		feu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o victime.o victime.cpp

pompier.o: pompier.cpp pompier.h \
		pda.h \
		agent.h \
		plateau.h \
		element.h \
		feu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pompier.o pompier.cpp

pda.o: pda.cpp pda.h \
		agent.h \
		plateau.h \
		element.h \
		feu.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pda.o pda.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

