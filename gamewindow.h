#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemAnimation>
#include <QTimer>
#include <QPixmap>
#include <cstdlib>
#include "queue.h"
#include "yoshi.h"
#include "bg.h"
#include "lava.h"
#include "heart.h"
#include "coin.h"
#include "bplatform.h"
#include "mplatform.h"
#include "splatform.h"
#include "platform.h"

class Game : public QGraphicsView
{
	Q_OBJECT
	
	public:
		explicit Game(QTimer *time);
		~Game();
		QTimer *timer;
		QTimer *yTimer;
		QTimer *cTimer;
		void yLeft();
		void yRight();
		void yUp();
		void yDown();
		void yStop();
	private:
		QGraphicsScene *gScene;
		QPixmap *yPix;
		QPixmap *bPix;
		QPixmap *hPix;
		QPixmap *lPix;
		QPixmap *spPix;
		QPixmap *mpPix;
		QPixmap *bpPix;
		QPixmap *cPix;
		Yoshi *yoshi;
		Bg *background;
		Bg *background2;
		Heart *heart;
		Lava *lava;
		Coin *coin;
		Queue<Platform*> platforms;
		Coin *sCoin;
		int pSize;
		int pLoc;
	public slots:
		void animate();
		void newCoin();
};

#endif
