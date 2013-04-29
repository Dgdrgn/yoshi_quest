#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QtGui>
#include "gamewindow.h"
#include "startwindow.h"
#include "yoshi.h"
//#include "pausewindow.h"

class QAction;

#define WINDOW_MAX_X 700
#define WINDOW_MAX_Y 500

class Main : public QMainWindow
{
	Q_OBJECT
	
	public:
		explicit Main();
		~Main();
		void switchGame();
		QPushButton *startG;
		QPushButton *pauseG;
		QPushButton *quitG;
		QFormLayout *form;
		QTextEdit *info;
		
	private:
		Start *sScreen;
		Game *gScreen;
		QTimer *time;
		QDockWidget *dWidget;
		QWidget *dock;
		QVBoxLayout *layout;
	protected:
		void keyPressEvent(QKeyEvent *e);
	public slots:
		//void game();
		void pause();
		void start();
};

#endif
