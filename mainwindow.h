#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QtGui>
#include "gamewindow.h"
#include "startwindow.h"
#include "yoshi.h"
#include <deque>
#include <string>

class QAction;

#define WINDOW_MAX_X 500
#define WINDOW_MAX_Y 500

/** A class for the main window of the game
@author Jesus Garcia*/

struct ScorePair
{
	int sc;
	string name;
	bool operator < (const ScorePair& pair) const
	{
		return (sc < pair.sc);
	}
};

class Main : public QMainWindow
{
	Q_OBJECT
	
	public:
		explicit Main();
		~Main();
		void switchGame();
		QWidget *star;
		/**Text Boxes*/
		QLineEdit *name;
		/**String where textbox input is saved*/
		QString n;
		/**creates menu*/
		void newMenus();
		void newActions();
		/**Actions for menu bar*/
		QAction *quit;
		QAction *start;
		QAction *pause;
		QAction *high;
		QAction *instructions;
		QAction *controls;
		/**Menus for menu bar*/
		QMenu *file;
		QMenu *options;
		QMenu *help;
		
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
		
		void selectionSort();
		
		/**high scores*/
		deque<ScorePair*> highSc;
		QHBoxLayout *r1;
		QHBoxLayout *r2;
		QHBoxLayout *r3;
		QHBoxLayout *r4;
		QHBoxLayout *r5;
		QHBoxLayout *r6;
		QHBoxLayout *r7;
		QHBoxLayout *r8;
		QHBoxLayout *r9;
		QHBoxLayout *r10;
		QHBoxLayout *r11;
		
	protected:
		void keyPressEvent(QKeyEvent *e);
		void keyReleaseEvent(QKeyEvent *e);
	public slots:
		void pauseGame();
		void startGame();
		void highScores();
		void instruct();
		void keyControls();
		void startG();
};

#endif
