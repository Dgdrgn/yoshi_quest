#include "gamewindow.h"

void Game::collisions()
{
	for(int i=0; i<things.size(); i++) {
		for(int j=0; j<platforms.size(); j++) {
			if(((things[i]->getHeight() + things[i]->getLocy()) == platforms[j]->getLocy()) && (things[i]->getLocx() >= platforms[j]->getLocx()) && ((things[i]->getWidth() + things[i]->getLocx()) == platforms[j]->getLocx())) {
				continue;
			}
			else {
				things[i]->setLocy((things[i]->getLocy())+1);
				things[i]->update();
			}
		}
		/*for(int k=0; k<things.size(); k++) {
			if(i == j) {
				continue;
			}
			else if(
		}*/
	}
}

void Game::animate()
{
	gScene->removeItem(sAmount);
	score += 10;
	QString temp = QString::number(score);
	sAmount = new QGraphicsSimpleTextItem(temp);
	sAmount->setPos(400, 460);
	sAmount->setFont(font);
	sAmount->setZValue(2);
	gScene->addItem(sAmount);
	background->move();
	background2->move();
	lava->move();
	sCoin->move();
	for(int l=0; l<things.size(); l++) {
		things[l]->move();
	}
	for(int i=0; i<platforms.size(); i++)
		platforms[i]->move();
	if(platforms.front()->getLocy() >= 500) {
		gScene->removeItem(platforms.front());
		platforms.pop_front();
		pSize = rand()%3;
		pLoc = rand()%3;
		switch(pSize) {
			case 0:
				switch(pLoc) {
					case 0:
						platforms.push_back(new SPlatform(spPix, 0, 0)); 
						break;
					case 1:
						platforms.push_back(new SPlatform(spPix, 200, 0));
						break;
					case 2:
						platforms.push_back(new SPlatform(spPix, 400, 0));
						break;
				}
				break;
			case 1:
				switch(pLoc) {
					case 0:
						platforms.push_back(new MPlatform(mpPix, 0, 0));
						break;
					case 1:
						platforms.push_back(new MPlatform(mpPix, 150, 0));
						break;
					case 2:
						platforms.push_back(new MPlatform(mpPix, 300, 0));
						break;
				}
				break;
			case 2:
				switch(pLoc) {
					case 0:
						platforms.push_back(new BPlatform(bpPix, 0, 0));
						break;
					case 1:
						platforms.push_back(new BPlatform(bpPix, 50, 0));
						break;
					case 2:
						platforms.push_back(new BPlatform(bpPix, 100, 0));
						break;
				}
				break;
		}
	}
	gScene->addItem(platforms.back());
}

void Game::newCoin()
{
	if(sCoin->getLocy() >= 500) {
		int randx = rand()%400;
		gScene->removeItem(sCoin);
		delete sCoin;
		sCoin = new Coin(cPix, randx, 7);
		gScene->addItem(sCoin);
	}
}

void Game::newGoomba()
{
	for(int i=0; i<things.size(); i++) {
		if(things[i]->getLocy() >= 500) {
			things.pop(i);
		}
	}
	int randx = rand()%450;
	things.push_back(new Goomba(gPix, randx, 0));
	gScene->addItem(things.back());
}

void Game::newKoopa()
{
	if(koopaCnt >= 50) {
		int randx = rand()%450;
		things.push_back(new Koopa(koopaPix, randx, 0));
		gScene->addItem(things.back());
		koopaCnt = 0;
	}
	else
		koopaCnt++;
}

Game::Game()
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	gScene = new QGraphicsScene();
	gScene->setSceneRect(0, 0, 500, 500);
	setScene(gScene);
	yPix = new QPixmap("img/yoshiw2.gif");
	bPix = new QPixmap("img/bg.gif");
	hPix = new QPixmap("img/heart.gif");
	lPix = new QPixmap("img/lava1.gif");
	bpPix = new QPixmap("img/bPlatform.gif");
	mpPix = new QPixmap("img/mPlatform.gif");
	spPix = new QPixmap("img/sPlatform.gif");
	cPix = new QPixmap("img/coin.gif");
	gPix = new QPixmap("img/goombaw1.gif");
	koopaPix = new QPixmap("img/koopaw1r.gif");
	koopaCnt = 0;
	background = new Bg(bPix, 0, 0);
	background2 = new Bg(bPix, 0, -680);
	things.push_back(new Yoshi(yPix, 225, 225));
	coin = new Coin(cPix, 170, 460);
	sCoin = new Coin(cPix, 500, 500);
	coin->setZValue(2);
	things.push_back(new Goomba(gPix, 0, -36));
	heart = new Heart(hPix, 20, 465);
	heart->setZValue(2);
	font.setPixelSize(30);
	sLabel = new QGraphicsSimpleTextItem("Score: ");
	sLabel->setPos(300, 460);
	sLabel->setFont(font);
	sLabel->setZValue(2);
	score = 0;
	QString temp = QString::number(score);
	sAmount = new QGraphicsSimpleTextItem(temp);
	sAmount->setPos(400, 460);
	sAmount->setFont(font);
	sAmount->setZValue(2);
	lives = 3;
	temp = QString::number(lives);
	lAmount = new QGraphicsSimpleTextItem(temp);
	lAmount->setPos(70, 460);
	lAmount->setFont(font);
	lAmount->setZValue(2);
	nCoins = 0;
	temp = QString::number(nCoins);
	cAmount = new QGraphicsSimpleTextItem(temp);
	cAmount->setPos(210, 460);
	cAmount->setFont(font);
	cAmount->setZValue(2);
	lava = new Lava(lPix, 0, 451);
	lava->setZValue(1);
	platforms.push_back(new BPlatform(bpPix, 50, 400));
	platforms.push_back(new BPlatform(bpPix, 50, 300));
	platforms.push_back(new MPlatform(mpPix, 50, 200));
	platforms.push_back(new MPlatform(mpPix, 50, 100));
	platforms.push_back(new SPlatform(spPix, 50, 0));
	gScene->addItem(background);
	gScene->addItem(background2);
	gScene->addItem(lava);
	gScene->addItem(heart);
	gScene->addItem(coin);
	gScene->addItem(sLabel);
	gScene->addItem(sAmount);
	gScene->addItem(lAmount);
	gScene->addItem(cAmount);
	for(int k=0; k<things.size(); k++)
		gScene->addItem(things[k]);
	
	for(int i=0; i<platforms.size(); i++)
		gScene->addItem(platforms[i]);
	
	timer = new QTimer(this);
	timer->setInterval(50);
	connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
	connect(timer, SIGNAL(timeout()), this, SLOT(collisions()));
	timer->start();
	cTimer = new QTimer(this);
	cTimer->setInterval(10000);
	connect(cTimer, SIGNAL(timeout()), this, SLOT(newCoin()));
	cTimer->start();
	eTimer = new QTimer(this);
	eTimer->setInterval(5);
	connect(eTimer, SIGNAL(timeout()), this, SLOT(newGoomba()));
	connect(eTimer, SIGNAL(timeout()), this, SLOT(newKoopa()));
}

Game::~Game()
{
	delete gScene;
}
