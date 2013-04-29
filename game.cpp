#include <QtGui/QApplication>
#include "mainwindow.h"

/**
@mainpage Yoshi's Quest
@section purpose Purpose/Overview
The following classes are for the game "Yoshi's Underwater Adventure, 
a game created using C++ and Qt.
@section requirements Requirements
The game must use timers to control movements, implement GUI user input 
classes, create and destroy graphical objects dynamically, and handle GUI-
based events in Qt.
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Main w;

    w.show();

    return a.exec();
}
