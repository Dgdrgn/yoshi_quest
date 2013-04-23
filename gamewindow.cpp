#include "gamewindow.h"

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
	goomba->move();
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
	if(sCoin->getLocy() >= 450) {
		int randx = rand()%400;
		gScene->removeItem(sCoin);
		gScene->removeItem(goomba);
		delete sCoin;
		delete goomba;
		sCoin = new Coin(cPix, randx, 7);
		goomba = new Goomba(gPix, randx, -36);
		gScene->addItem(sCoin);
		gScene->addItem(goomba);
	}
}

Game::Game()
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	gScene = new QGraphicsScene();
	setScene(gScene);
	yPix = new QPixmap("img/yoshiw2.jpg");
	bPix = new QPixmap("img/bg.jpg");
	hPix = new QPixmap("img/heart.jpg");
	lPix = new QPixmap("img/lava1.jpg");
	bpPix = new QPixmap("img/bPlatform.jpg");
	mpPix = new QPixmap("img/mPlatform.jpg");
	spPix = new QPixmap("img/sPlatform.jpg");
	cPix = new QPixmap("img/coin.jpg");
	gPix = new QPixmap("img/goombaw1.jpg");
	background = new Bg(bPix, 0, 0);
	background2 = new Bg(bPix, 0, -680);
	yoshi = new Yoshi(yPix, 225, 225);
	coin = new Coin(cPix, 170, 460);
	sCoin = new Coin(cPix, 500, 500);
	coin->setZValue(2);
	goomba = new Goomba(gPix, 0, -36);
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
	Platform *tempP = new BPlatform(bpPix, 50, 400);
	platforms.push_back(tempP);
	gScene->addItem(background);
	gScene->addItem(background2);
	gScene->addItem(lava);
	gScene->addItem(heart);
	gScene->addItem(coin);
	gScene->addItem(yoshi);
	gScene->addItem(sLabel);
	gScene->addItem(sAmount);
	gScene->addItem(lAmount);
	gScene->addItem(cAmount);
	gScene->addItem(goomba);
	for(int i=3; i>=0; i--) {
		int yLoc = i*100;
		pSize = rand()%3;
		pLoc = rand()%3;
		switch(pSize) {
			case 0:
				switch(pLoc) {
					case 0:
						platforms.push_back(new SPlatform(spPix, 0, yLoc)); 
						break;
					case 1:
						platforms.push_back(new SPlatform(spPix, 200, yLoc));
						break;
					case 2:
						platforms.push_back(new SPlatform(spPix, 400, yLoc));
						break;
				}
				break;
			case 1:
				switch(pLoc) {
					case 0:
						platforms.push_back(new MPlatform(mpPix, 0, yLoc));
						break;
					case 1:
						platforms.push_back(new MPlatform(mpPix, 150, yLoc));
						break;
					case 2:
						platforms.push_back(new MPlatform(mpPix, 300, yLoc));
						break;
				}
				break;
			case 2:
				switch(pLoc) {
					case 0:
						platforms.push_back(new BPlatform(bpPix, 0, yLoc));
						break;
					case 1:
						platforms.push_back(new BPlatform(bpPix, 50, yLoc));
						break;
					case 2:
						platforms.push_back(new BPlatform(bpPix, 100, yLoc));
						break;
				}
				break;
		}
	}
	for(int i=0; i<platforms.size(); i++)
		gScene->addItem(platforms[i]);
	timer = new QTimer(this);
	timer->setInterval(100);
	connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
	timer->start();
	cTimer = new QTimer(this);
	cTimer->setInterval(10000);
	connect(cTimer, SIGNAL(timeout()), this, SLOT(newCoin()));
	cTimer->start();
}

Game::~Game()
{
	delete gScene;
}

void Game::yLeft()
{
	yoshi->right = false;
	yoshi->walk1();
}

void Game::yRight()
{
	yoshi->right = true;
	yoshi->walk1();
}

void Game::yUp()
{
	yoshi->jump();
}

void Game::yDown()
{
	yoshi->jump();
}

void Game::yStop()
{
	yoshi->stop();
}
