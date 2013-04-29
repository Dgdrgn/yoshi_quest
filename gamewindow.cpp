#include "gamewindow.h"
#include <cmath>

void Game::life(int choice)
{
	QString temp = "";
	switch(choice) {
		case 0:
			lives--;
			gScene->removeItem(lAmount);
			temp = QString::number(lives);
			lAmount = new QGraphicsSimpleTextItem(temp);
			lAmount->setPos(70, 460);
			lAmount->setFont(font);
			lAmount->setZValue(2);
			gScene->addItem(lAmount);
			break;
		case 1:
			lives++;
			gScene->removeItem(lAmount);
			temp = QString::number(lives);
			lAmount = new QGraphicsSimpleTextItem(temp);
			lAmount->setPos(70, 460);
			lAmount->setFont(font);
			lAmount->setZValue(2);
			gScene->addItem(lAmount);
			break;
	}
	if(lives == 0) {
		QGraphicsSimpleTextItem *over = new QGraphicsSimpleTextItem("Game Over!");
		over->setPos(50, 100);
		QFont *fonto = new QFont;
		fonto->setPixelSize(50);
		over->setFont(*fonto);
		over->setZValue(3);
		gScene->addItem(over);
		timer->stop();
	}
}

/****************************************************************/
/*checks for collisions*/
void Game::collisions()
{
	int tX = yoshi->getLocx();
	int tY = yoshi->getLocy();
	if(tY2 != 450) {
		things[0]->setLocy(things[0]->getLocy()+1);
		things[0]->update();
	}
	for(int k=0; k<things.size(); k++) {
		int pX = things[k]->getLocx();
		int pY = things[k]->getLocy();
		if(abs(tX-pX) < 30 && abs(tY-pY) < 30) {
			if(spawnCnt >=10) {
				if(things[k]->type == Thing::goombaEnemy) {
					life(0);
				}
				else if(things[k]->type == Thing::koopaEnemy) {
					life(0);
				}
				else if(things[k]->type == Thing::billEnemy) {
					life(0);
				}
				else if(things[k]->type == Thing::kamekEnemy) {
					life(0);
				}
				else if(things[k]->type == Thing::ammo) {
					life(0);
				}
				else if(things[k]->type == Thing::item) {
					gScene->removeItem(things[k]);
					things.pop(k);
					nCoins++;
					gScene->removeItem(cAmount);
					QString temp = QString::number(nCoins);
					cAmount = new QGraphicsSimpleTextItem(temp);
					cAmount->setPos(210, 460);
					cAmount->setFont(font);
					cAmount->setZValue(2);
					gScene->addItem(cAmount);
					if(nCoins == 5) {
							life(1);
						nCoins = 0;
					}
				}
				else if(things[k]->type == Thing::life) {
					gScene->removeItem(things[k]);
					things.pop(k);
					life(1);
				}
				spawnCnt = 0;
			}
			else if(things[k]->type == Thing::hero && spawnCnt < 10) {
				spawnCnt++;
			}
		}
	}
}	

/****************************************************************/
/*animates the game (moves the enemies, platforms, etc.)*/
void Game::animate()
{
	
	//updates score
	gScene->removeItem(sAmount);
	score += 10;
	QString temp = QString::number(score);
	sAmount = new QGraphicsSimpleTextItem(temp);
	sAmount->setPos(400, 460);
	sAmount->setFont(fontT);
	sAmount->setZValue(2);
	gScene->addItem(sAmount);
		
	//moves all other things
	for(int l=0; l<things.size(); l++) {
		things[l]->move();
		if(things[l]->type == Thing::kamekEnemy && things[l]->frame == 4) {
			if(things[l]->right) {
				int y = things[l]->getLocy();
				int x = things[l]->getLocx() - 28;
				newMagic(x, y, 1);
			}
			else {
				int y = things[l]->getLocy();
				int x = things[l]->getLocx() + 3;
				newMagic(x, y, 0);
			}
		}
		if(things[l]->type == Thing::kamekEnemy && things[l]->del) {
			gScene->removeItem(things[l]);
			things.pop(l);
		}
	}
	if(timeCnt >= 1000) {
		for(int m=1; m<things.size(); m++) {
			things[m]->addVelx();
			things[m]->addVely();
		}	
		timeCnt = 0;	
	}
	else
		timeCnt++;
	//collisions
	collisions();
}

/****************************************************************/
/*adds a new coin*/
void Game::newCoin()
{
	if(coinCnt >= 1000) {
		int randx = rand()%450;
		things.push_back(new Coin(coinPix, randx, 0));
		gScene->addItem(things.back());
		coinCnt = 0;
	}
	else
		coinCnt++;
}

/****************************************************************/
/*adds a new heart*/
void Game::newHeart()
{
	if(heartCnt == 1000) {
		for(int i=0; i<things.size(); i++) {
			if(things[i]->type == Thing::other)
				things.pop(i);
		}
	}
	if(heartCnt >= 2000) {
		int randx = rand()%450;
		int randy = 0;
		switch(rand()%5) {
			case 0:
				randy = 25;
				break;
			case 1:
				randy = 125;
				break;
			case 2:
				randy = 225;
				break;
			case 3:
				randy = 325;
				break;
			case 4:
				randy = 425;
				break;
		}
		things.push_back(new Heart(hPix, randx, randy));
		gScene->addItem(things.back());
		heartCnt = 0;
	}
	else
		heartCnt++;
}

/****************************************************************/
/*deletes any "thing" that goes off screen*/
void Game::offScreen()
{
	for(int i=0; i<things.size(); i++) {
		if(things[i]->getLocy() >= 500) {
			if(things[i]->type == Thing::hero) {
				lives--;
				gScene->removeItem(lAmount);
				delete lAmount;
				lAmount = new QGraphicsSimpleTextItem(QString::number(lives));
				lAmount->setPos(70, 460);
				lAmount->setFont(font);
				lAmount->setZValue(2);
				gScene->addItem(lAmount);
			}
			gScene->removeItem(things[i]);
			things.pop(i);
		}
	}
}

/****************************************************************/
/*adds a new goomba*/
void Game::newGoomba()
{
	if(goombaCnt >= 100) {
		int randx = rand()%450;
		int randy = ((rand()%5)*100)-50;
		switch(rand()%2) {
			case 0:
				things.push_back(new Goomba(goombaPix, randx, randy, 0));
				break;
			case 1:
				things.push_back(new Goomba(goombaPix, randx, randy, 1));
				break;
		}
		gScene->addItem(things.back());
		goombaCnt = 0;
	}
	else
		goombaCnt++;
}

/****************************************************************/
/*adds a new koopa*/
void Game::newKoopa()
{
	if(koopaCnt >= 150) {
		int randx = rand()%450;
		switch(rand()%2) {
			case 0:
				things.push_back(new Koopa(koopaPix, randx, 0, 0));
				break;
			case 1:
				things.push_back(new Koopa(koopaPix, randx, 0, 1));
				break;
		}
		gScene->addItem(things.back());
		koopaCnt = 0;
	}
	else
		koopaCnt++;
}

/****************************************************************/
/*adds a new kamek*/
void Game::newKamek()
{
	if(kamekCnt >= 500) {
		int randx = rand()%450;
		int randy = ((rand()%5)*100)-50;
		if(randx <= 250)
			things.push_back(new Kamek(kamekRPix, randx, randy, 0));
		else
			things.push_back(new Kamek(kamekLPix, randx, randy, 1));
		gScene->addItem(things.back());
		kamekCnt = 0;
		boolMagic = false;
	}
	else
		kamekCnt++;	
}

/****************************************************************/
/*adds a new bill*/
void Game::newBill()
{
	if(billCnt >= 750) {
		int randy = rand()%450;
		switch(rand()%2) {
			case 0:
				things.push_back(new Bill(billLPix, -68, randy, 0));
				break;
			case 1:
				things.push_back(new Bill(billRPix, 500, randy, 1));
				break;
		}
		gScene->addItem(things.back());
		billCnt = 0;
	}
	else
		billCnt++;
}

/****************************************************************/
/*adds a new magic item*/
void Game::newMagic(int x, int y, bool r)
{
	if(!boolMagic) {
		things.push_back(new Magic(magicPix, x, y, r));
		gScene->addItem(things.back());
		boolMagic = true;
	}
}

/****************************************************************/
/*constructor of the game graphics view*/
Game::Game(QTimer *t, QString n)
{
	setFixedSize(525, 525);
	setFocus();
	
	//removes scroll bars
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	//creates a new scene and sets it in a fixed location
	gScene = new QGraphicsScene();
	gScene->setSceneRect(0, 0, 500, 500);
	setScene(gScene);
	
	//creates the Pixmaps of all the "things" for their constructors
	yPix = new QPixmap("img/yoshiw2.gif");
	bPix = new QPixmap("img/bg.jpg");
	hPix = new QPixmap("img/heart.gif");
	coinPix = new QPixmap("img/coin.gif");
	goombaPix = new QPixmap("img/goombaw1.gif");
	koopaPix = new QPixmap("img/koopaw1r.gif");
	kamekLPix = new QPixmap("img/kamek1.gif");
	kamekRPix = new QPixmap("img/kamek21.gif");
	billLPix = new QPixmap("img/lbill.gif");
	billRPix = new QPixmap("img/rbill.gif");
	magicPix = new QPixmap("img/magic.gif");
	
	/*creates "things"*/
	//background
	background = new Bg(bPix, 0, 0);
	
	//adds Yoshi (playable character) to list
	yoshi = new Yoshi(yPix, 225, 405);
	things.push_back(yoshi);
	
	//coin on stats panel (lava)
	sCoin = new Coin(coinPix, 170, 460);
	sCoin->setZValue(2);
	
	//heart
	heart = new Heart(hPix, 20, 465);
	heart->setZValue(2);
	
	/*create text*/
	//font size
	font.setPixelSize(30);
	fontT.setPixelSize(15);
	
	//word "Score"
	sLabel = new QGraphicsSimpleTextItem("Score: ");
	sLabel->setPos(300, 460);
	sLabel->setFont(fontT);
	sLabel->setZValue(2);
	
	//actual score value
	score = 0;
	QString temp = QString::number(score);
	sAmount = new QGraphicsSimpleTextItem(temp);
	sAmount->setPos(400, 460);
	sAmount->setFont(fontT);
	sAmount->setZValue(2);
	
	//lives
	lives = 3;
	temp = QString::number(lives);
	lAmount = new QGraphicsSimpleTextItem(temp);
	lAmount->setPos(70, 460);
	lAmount->setFont(font);
	lAmount->setZValue(2);
	
	//number of coins collected
	nCoins = 0;
	temp = QString::number(nCoins);
	cAmount = new QGraphicsSimpleTextItem(temp);
	cAmount->setPos(210, 460);
	cAmount->setFont(font);
	cAmount->setZValue(2);
	
	
	//name
	nLabel = new QGraphicsSimpleTextItem(n);
	nLabel->setPos(300, 480);
	nLabel->setFont(fontT);
	nLabel->setZValue(2);
	
	
	//now barrage the scene with the items!
	gScene->addItem(background);
	gScene->addItem(heart);
	gScene->addItem(sCoin);
	gScene->addItem(sLabel);
	gScene->addItem(nLabel);
	gScene->addItem(sAmount);
	gScene->addItem(lAmount);
	gScene->addItem(cAmount);
	
	for(int k=1; k<things.size(); k++)
		gScene->addItem(things[k]);
	
	gScene->addItem(yoshi);
	
	//timers
	timer = t;
	
	//counters
	goombaCnt = 0;
	koopaCnt = 0;
	kamekCnt = 0;
	billCnt = 0;
	coinCnt = 0;
	heartCnt = 0;
	yoshiJCnt = 0;
	spawnCnt = 0;
	timeCnt = 0;
	boolMagic = false;
	
	//connect to slot functions
	connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newCoin()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newGoomba()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newKoopa()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newKamek()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newBill()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newHeart()));
	connect(timer, SIGNAL(timeout()), this, SLOT(offScreen()));
	
	//timer->start();
}

/****************************************************************/
/*destructor*/
Game::~Game()
{
	
}

/****************************************************************/
/*for keyboard inputs*/
void Game::yoshiW1()
{
	if(yoshi && timer->isActive())
		yoshi->walkR();
}

void Game::yoshiW2()
{
	if(yoshi && timer->isActive())
		yoshi->walkL();
}

void Game::yoshiC()
{
	if(yoshi && timer->isActive())
		yoshi->crouch();
}

void Game::yoshiJ()
{
	if(yoshi && timer->isActive()) {
		yoshi->jump();
		yoshiJCnt++;
	}
}

void Game::yoshiI()
{
	yoshiJCnt = 14;
	yoshi->stop();
}
