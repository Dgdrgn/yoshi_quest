#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemAnimation>
#include <QTimer>
#include <QPixmap>
#include <QFont>
#include <cstdlib>
#include "mylist.h"
#include "queue.h"
#include "yoshi.h"
#include "bg.h"
#include "lava.h"
#include "heart.h"
#include "coin.h"
#include "goomba.h"
#include "koopa.h"
#include "kamek.h"
#include "bill.h"
#include "magic.h"
#include "bplatform.h"
#include "mplatform.h"
#include "splatform.h"
#include "platform.h"

class Game : public QGraphicsView
{
	Q_OBJECT
	
	public:
		explicit Game();
		~Game();
		QTimer *timer;
		
	private:
		QGraphicsScene *gScene;
		QPixmap *yPix;
		QPixmap *bPix;
		QPixmap *hPix;
		QPixmap *lPix;
		QPixmap *spPix;
		QPixmap *mpPix;
		QPixmap *bpPix;
		QPixmap *coinPix;
		QPixmap *goombaPix;
		QPixmap *koopaPix;
		QPixmap *kamekLPix;
		QPixmap *kamekRPix;
		QPixmap *billLPix;
		QPixmap *billRPix;
		QPixmap *magicPix;
		Bg *background;
		Bg *background2;
		Heart *heart;
		Lava *lava;
		Queue<Platform*> platforms;
		MyList<Thing*> things;
		Coin *sCoin;
		int pSize;
		int pLoc;
		int score;
		int lives;
		int nCoins;
		QGraphicsSimpleTextItem* sLabel;
		QGraphicsSimpleTextItem* sAmount;
		QGraphicsSimpleTextItem* lAmount;
		QGraphicsSimpleTextItem* cAmount;
		QFont font;
		int goombaCnt;
		int koopaCnt;
		int kamekCnt;
		int billCnt;
		int coinCnt;
		
	public slots:
		void animate();
		void newCoin();
		void newGoomba();
		void newKoopa();
		void newKamek();
		void newBill();
		void newMagic();
		void offScreen();
		void collisions();
};

#endif
