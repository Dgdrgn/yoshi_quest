#include "gamewindow.h"
#include <cmath>

/**
Either increments or decrements a life. Checks for game over.
@param choice Integer that determines whether life increments or decrements.
*/
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
		over->setPos(100, 225);
		QFont *fonto = new QFont;
		fonto->setPixelSize(50);
		over->setFont(*fonto);
		over->setZValue(3);
		gScene->addItem(over);
		timer->stop();
	}
}

/**
Checks for collisions between the player and objects
*/
void Game::collisions()
{
	int tX = yoshi->getLocx();
	int tY = yoshi->getLocy();
	if(tY+yoshi->getHeight() < 450) {
		things[0]->setLocy(things[0]->getLocy()+1);
		things[0]->update();
	}
	if(spawnCnt >= 100) {
		for(int k=0; k<things.size(); k++) {
			int pX = things[k]->getLocx();
			int pY = things[k]->getLocy();
			if(abs(tX-pX) < 32 && abs(tY-pY) < 32) {
				if(things[k]->type == Thing::goombaEnemy) {
					life(0);
					spawnCnt = 0;
				}
				
				else if(things[k]->type == Thing::koopaEnemy) {
					life(0);
					spawnCnt = 0;
				}
				
				else if(things[k]->type == Thing::billEnemy) {
					life(0);
					spawnCnt = 0;
				}
				
				else if(things[k]->type == Thing::kamekEnemy) {
					life(0);
					spawnCnt = 0;
				}
				
				else if(things[k]->type == Thing::ammo) {
					life(0);
					spawnCnt = 0;
				}
				
				else if(things[k]->type == Thing::item) {
					gScene->removeItem(things[k]);
					things.pop(k);
					nCoins++;
					if(nCoins == 5) {
						life(1);
						nCoins = 0;
					}
					gScene->removeItem(cAmount);
					QString temp = QString::number(nCoins);
					cAmount = new QGraphicsSimpleTextItem(temp);
					cAmount->setPos(210, 460);
					cAmount->setFont(font);
					cAmount->setZValue(2);
					gScene->addItem(cAmount);
					gScene->removeItem(sAmount);
					score += 50;
					temp = QString::number(score);
					sAmount = new QGraphicsSimpleTextItem(temp);
					sAmount->setPos(400, 450);
					sAmount->setFont(fontT);
					sAmount->setZValue(2);
					gScene->addItem(sAmount);
				}	
					
				else if(things[k]->type == Thing::life) {
					gScene->removeItem(things[k]);
					things.pop(k);
					life(1);
				}
			}
		}
	}
	else {
		spawnCnt++;
	}
}	

/**Moves the objects in the game*/
void Game::animate()
{
	
	//updates score
	gScene->removeItem(sAmount);
	score += 10;
	QString temp = QString::number(score);
	sAmount = new QGraphicsSimpleTextItem(temp);
	sAmount->setPos(400, 450);
	sAmount->setFont(fontT);
	sAmount->setZValue(2);
	gScene->addItem(sAmount);
		
	//moves all other things
	for(int l=0; l<things.size(); l++) {
		things[l]->move();
		if(things[l]->type == Thing::kamekEnemy && things[l]->frame == 4) {
			if(things[l]->right) {
				int y = things[l]->getLocy();
				int x = things[l]->getLocx() +3;
				newMagic(x, y, 0);
			}
			else {
				int y = things[l]->getLocy();
				int x = things[l]->getLocx() -28;
				newMagic(x, y, 1);
			}
		}
		if(things[l]->type == Thing::kamekEnemy && things[l]->del) {
			gScene->removeItem(things[l]);
			things.pop(l);
		}
	}
	if(timeCnt >= 500) {
		interval -= (interval/64);
		timer->setInterval(interval);
		timeCnt = 0;
		levelCnt++;
		gScene->removeItem(levelAmount);
		temp = QString::number(levelCnt);
		levelAmount = new QGraphicsSimpleTextItem(temp);
		levelAmount->setPos(400, 480);
		levelAmount->setFont(fontT);
		levelAmount->setZValue(2);
		gScene->addItem(levelAmount);
	}
	else
		timeCnt++;
	//collisions
	collisions();
}

/**Adds a new coin*/
void Game::newCoin()
{
	if(coinCnt >= 150) {
		int randx = rand()%450;
		things.push_back(new Coin(coinPix, randx, 0, velx, vely));
		gScene->addItem(things.back());
		coinCnt = 0;
	}
	else
		coinCnt++;
}

/**Adds a new heart*/
void Game::newHeart()
{
	if(heartCnt >= 100) {
		for(int i=0; i<things.size(); i++) {
			if(things[i]->type == Thing::life) {
				gScene->removeItem(things[i]);
				things.pop(i);
			}
		}
	}
	if(heartCnt >= 500) {
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
		things.push_back(new Heart(hPix, randx, randy, 0, 0));
		gScene->addItem(things.back());
		heartCnt = 0;
	}
	else
		heartCnt++;
}

/*Deletes any "thing" that goes off screen*/
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

/**Adds a new goomba*/
void Game::newGoomba()
{
	if(goombaCnt >= 100) {
		int randx = rand()%450;
		int randy = ((rand()%5)*100)-50;
		switch(rand()%2) {
			case 0:
				things.push_back(new Goomba(goombaPix, randx, randy, velx, vely, 0));
				break;
			case 1:
				things.push_back(new Goomba(goombaPix, randx, randy, velx, vely, 1));
				break;
		}
		gScene->addItem(things.back());
		goombaCnt = 0;
	}
	else
		goombaCnt++;
}

/**Adds a new koopa*/
void Game::newKoopa()
{
	if(koopaCnt >= 150) {
		int randx = rand()%450;
		switch(rand()%2) {
			case 0:
				things.push_back(new Koopa(koopaPix, randx, 0, velx, vely, 0));
				break;
			case 1:
				things.push_back(new Koopa(koopaPix, randx, 0, velx, vely, 1));
				break;
		}
		gScene->addItem(things.back());
		koopaCnt = 0;
	}
	else
		koopaCnt++;
}

/**Adds a new kamek*/
void Game::newKamek()
{
	if(kamekCnt >= 250) {
		int randx = rand()%450;
		int randy = ((rand()%5)*100)-50;
		if(randx <= 250)
			things.push_back(new Kamek(kamekLPix, randx, randy, velx, vely, 1));
		else
			things.push_back(new Kamek(kamekRPix, randx, randy, velx, vely, 0));
		gScene->addItem(things.back());
		kamekCnt = 0;
		boolMagic = true;
	}
	else
		kamekCnt++;	
}

/**Adds a new bill*/
void Game::newBill()
{
	if(billCnt >= 450) {
		int randy = rand()%450;
		switch(rand()%2) {
			case 0:
				things.push_back(new Bill(billLPix, -68, randy, velx, vely, 0));
				break;
			case 1:
				things.push_back(new Bill(billRPix, 500, randy, velx, vely, 1));
				break;
		}
		gScene->addItem(things.back());
		billCnt = 0;
	}
	else
		billCnt++;
}

/**Adds a new magic item
@param x The x location of the magic item
@param y The y location of the magic item
@param r Boolean that determines what direction to go to
*/
void Game::newMagic(int x, int y, bool r)
{
	if(boolMagic) {
		things.push_back(new Magic(magicPix, x, y, velx, vely, !r));
		gScene->addItem(things.back());
		boolMagic = false;
	}
}

/**Constructor*/
Game::Game(QTimer *t, QString n)
{
	setFixedSize(500, 500);
	setFocus();
	
	//removes scroll bars
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	//creates a new scene and sets it in a fixed location
	gScene = new QGraphicsScene();
	gScene->setSceneRect(0, 0, 500, 500);
	setScene(gScene);
	
	//creates the Pixmaps of all the "things" for their constructors
	yPix = new QPixmap("img/yoshiw2.png");
	bPix = new QPixmap("img/bg.png");
	hPix = new QPixmap("img/heart.png");
	coinPix = new QPixmap("img/coin.png");
	goombaPix = new QPixmap("img/goombaw1.png");
	koopaPix = new QPixmap("img/koopaw1r.png");
	kamekLPix = new QPixmap("img/kamek1.png");
	kamekRPix = new QPixmap("img/kamek21.png");
	billLPix = new QPixmap("img/lbill.png");
	billRPix = new QPixmap("img/rbill.png");
	magicPix = new QPixmap("img/magic.png");
	
	/*creates "things"*/
	//background
	background = new Bg(bPix, 0, 0, 0, 0);
	
	//adds Yoshi (playable character) to list
	yoshi = new Yoshi(yPix, 225, 405, 1, 1);
	things.push_back(yoshi);
	yoshi->setZValue(3);
	//coin on stats panel (lava)
	sCoin = new Coin(coinPix, 170, 460, 0, 0);
	sCoin->setZValue(2);
	
	//heart
	heart = new Heart(hPix, 20, 465, 0, 0);
	heart->setZValue(2);
	
	/*create text*/
	//font size
	font.setPixelSize(30);
	fontT.setPixelSize(14);
	
	//word "Score"
	sLabel = new QGraphicsSimpleTextItem("Score: ");
	sLabel->setPos(300, 450);
	sLabel->setFont(fontT);
	sLabel->setZValue(3);
	nameLabel = new QGraphicsSimpleTextItem("Name: ");
	nameLabel->setPos(300, 465);
	nameLabel->setFont(fontT);
	nameLabel->setZValue(3);
	levelLabel = new QGraphicsSimpleTextItem("Level: ");
	levelLabel->setPos(300, 480);
	levelLabel->setFont(fontT);
	levelLabel->setZValue(3);
	
	//actual score value
	score = 0;
	QString temp = QString::number(score);
	sAmount = new QGraphicsSimpleTextItem(temp);
	sAmount->setPos(400, 450);
	sAmount->setFont(fontT);
	sAmount->setZValue(3);
	
	//lives
	lives = 3;
	temp = QString::number(lives);
	lAmount = new QGraphicsSimpleTextItem(temp);
	lAmount->setPos(70, 460);
	lAmount->setFont(font);
	lAmount->setZValue(3);
	
	//number of coins collected
	nCoins = 0;
	temp = QString::number(nCoins);
	cAmount = new QGraphicsSimpleTextItem(temp);
	cAmount->setPos(210, 460);
	cAmount->setFont(font);
	cAmount->setZValue(2);
	
	//level
	levelCnt = 1;
	temp = QString::number(levelCnt);
	levelAmount = new QGraphicsSimpleTextItem(temp);
	levelAmount->setPos(400, 480);
	levelAmount->setFont(fontT);
	levelAmount->setZValue(2);
	gScene->addItem(levelAmount);
	
	//name
	nLabel = new QGraphicsSimpleTextItem(n);
	nLabel->setPos(400, 465);
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
	gScene->addItem(nameLabel);
	gScene->addItem(levelLabel);
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
	spawnCnt = 100;
	timeCnt = 0;
	interval = timer->interval();
	velx = 1;
	vely = 1;
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
}

/**Destructor*/
Game::~Game()
{
	
}

/*Fuctions that are called in the Main class by keyboard inputs*/
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
	if(yoshi && timer->isActive()) {
			yoshi->crouch();
	}
}

void Game::yoshiJ()
{
	if(yoshi && timer->isActive()) {
		yoshi->jump();
	}
}

void Game::yoshiI()
{
	yoshi->idle();
}
