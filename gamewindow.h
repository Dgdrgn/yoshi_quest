#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemAnimation>
#include <QTimer>
#include <QPixmap>
#include "yoshi.h"
#include "bg.h"

class Game : public QGraphicsView
{
	Q_OBJECT
	
	public:
		explicit Game(QTimer *time);
		~Game();
		QTimer *timer;
		QTimer *ytimer;
		void yLeft();
		void yRight();
		void yUp();
		void yDown();
		void yStop();
	private:
		QGraphicsScene *gScene;
		QPixmap *yPix;
		QPixmap *bPix;
		Yoshi *yoshi;
		Bg *background;
		Bg *background2;
	public slots:
		void animate();
};

#endif
