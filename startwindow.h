#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QApplication>
#include <QtGui>

class Start : public QWidget
{
	Q_OBJECT
	
	public:
		explicit Start();
		~Start();
		void show();
	private:
		QVBoxLayout *layout;
		QGraphicsView *sView;
		QGraphicsScene *sScene;
		QGraphicsPixmapItem *sMenu;
		
	public slots:
		
};

#endif
