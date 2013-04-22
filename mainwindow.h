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
#include <QKeyEvent>
#include "gamewindow.h"
#include "startwindow.h"
#include "yoshi.h"
//#include "pausewindow.h"

class QAction;

#define WINDOW_MAX_X 525
#define WINDOW_MAX_Y 525

class Main : public QMainWindow
{
	Q_OBJECT
	
	public:
		explicit Main();
		~Main();
		void show();
		void switchGame();
	private:
		Start *sScreen;
		Game *gScreen;
		QTimer *time;
		QVBoxLayout *layout;
		void createActions();
		void createMenus();
		QMenu *fileMenu;
		QAction *exitAct;
		QWidget *window;
	protected:
		void keyPressEvent(QKeyEvent *e);
		void keyReleaseEvent(QKeyEvent *e);
	private slots:
		
/*	public slots:
		game();
		pause();
		start();*/
};

#endif
