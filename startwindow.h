#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QApplication>
#include <QtGui>

class Start : public QGraphicsView
{
	Q_OBJECT
	
	public:
		explicit Start();
		~Start();
		void show();
	private:
		QGraphicsScene *sScene;
		QGraphicsPixmapItem *sMenu;
		
	public slots:
		
};

#endif
