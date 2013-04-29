#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QApplication>
#include <QtGui>

/** A class for the start menu of the game
@author Jesus Garcia*/
class Start : public QGraphicsView
{
	Q_OBJECT
	
	public:
		explicit Start();
		~Start();
		void show();
	private:
		/**Scene of start window*/
		QGraphicsScene *sScene;
		/**Pixmap image of start window*/
		QGraphicsPixmapItem *sMenu;
		
	public slots:
		
};

#endif
