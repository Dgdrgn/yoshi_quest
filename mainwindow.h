#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemAnimation>
#include <QTimer>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLayout>
//#include "gamewindow.h"
#include "startwindow.h"
//#include "pausewindow.h"


#define WINDOW_MAX_X 625
#define WINDOW_MAX_Y 625

class Main : public QMainWindow
{
	Q_OBJECT
	
	public:
		explicit Main();
		~Main();
		void show();
	private:
		Start *sScreen;
		QTimer *time;
		QVBoxLayout *layout;
		void createActions();
		void createMenus();
		QMenu *fileMenu;
		QAction *exitAct;
		QWidget *window;
	private slots:
		
/*	public slots:
		game();
		pause();
		start();*/
};

#endif
