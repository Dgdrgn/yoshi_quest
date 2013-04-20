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


#define WINDOW_MAX_X 800
#define WINDOW_MAX_Y 800

class Main : public QMainWindow
{
	Q_OBJECT
	
	public:
		explicit Main();
		~Main();
		void show();
	private:
		QTimer *time;
		QMenuBar *mb;
		void createActions();
		void createMenus();
		QMenu *fileMenu;
		QAction *exitAct;
		QWidget *window;
	protected:
		//void contextMenuEvent(QContextMenuEvent *event);
	private slots:
		
/*	public slots:
		game();
		pause();
		start();*/
};

#endif
