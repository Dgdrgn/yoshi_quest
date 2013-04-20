#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemAnimation>
#include <QTimer>

class Start : public QGraphicsView
{
	Q_OBJECT
	
	public:
		explicit Start();
		~Start();
		void show();
	private:
		QGraphicsScene *sScene;
		
	public slots:
		
	protected:
		void keyPressEvent(QKeyEvent *e);
};

#endif
