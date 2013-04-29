#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QtGui>
#include "gamewindow.h"
#include "startwindow.h"
#include "yoshi.h"

class QAction;

#define WINDOW_MAX_X 725
#define WINDOW_MAX_Y 525

/** A class for the main window of the game
@author Jesus Garcia*/

class Main : public QMainWindow
{
	Q_OBJECT
	
	public:
		explicit Main();
		~Main();
		void switchGame();
		/**Push Buttons*/
		QPushButton *startG;
		QPushButton *pauseG;
		QPushButton *quitG;
		/**Text Boxes*/
		QTextEdit *info;
		QTextEdit *name;
		/**String where textbox input is saved*/
		QString n;
		
	private:
		/**Start screen object*/
		Start *sScreen;
		/**Game screen object*/
		Game *gScreen;
		/**Timer of whole game*/
		QTimer *time;
		/**Dock widget that holds buttons and textboxes*/
		QDockWidget *dWidget;
		/**Widget that goes in dock widget*/
		QWidget *dock;
		/**Layout of widget*/
		QVBoxLayout *layout;
		/**Music*/
		QSound *gMusic;
		bool isMusicPlaying;
	protected:
		void keyPressEvent(QKeyEvent *e);
		void keyReleaseEvent(QKeyEvent *e);
	public slots:
		void pause();
		void start();
		void musicPlay();
};

#endif
