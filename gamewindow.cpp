#include "gamewindow.h"

/****************************************************************/
/*respawns player*/
void Game::respawn()
{
	things.push_back(new Yoshi(yPix, 225, 390));
	gScene->addItem(things.back());
}

/****************************************************************/
/*checks for collisions*/
void Game::collisions()
{
	for(int i=0; i<things.size(); i++) {
		/*platforms*/
		if(things[i]->type != Thing::item && things[i]->type != Thing::billEnemy && things[i]->type != Thing::ammo) {
			for(int j=0; j<platforms.size(); j++) {
				int tX = things[i]->getLocx();
				int tY = things[i]->getLocy();
				int tW = things[i]->getWidth();
				int tH = things[i]->getHeight();
				int pX = platforms[j]->getLocx();
				int pW = platforms[j]->getWidth();
				if((tY+tH-50)%100 == 0 && (tX > pX))
					break;
				else if(tY+tH == 450)
					break;
				else {
					things[i]->setLocy(things[i]->getLocy()+1);
					things[i]->update();
				}
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
	sAmount->setFont(font);
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
	
	//collisions
	collisions();
}

/****************************************************************/
/*adds a new coin*/
void Game::newCoin()
{
	if(coinCnt >= 1000) {
		int randx = rand()%400;
		things.push_back(new Coin(coinPix, randx, 0));
		gScene->addItem(things.back());
		coinCnt = 0;
	}
	else
		coinCnt++;
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
				respawn();
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
	things.push_back(new Magic(magicPix, x, y, r));
	gScene->addItem(things.back());
}

/****************************************************************/
/*constructor of the game graphics view*/
Game::Game(QTimer *t)
{
	setFixedSize(525, 525);

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
	bpPix = new QPixmap("img/bPlatform.gif");
	mpPix = new QPixmap("img/mPlatform.gif");
	spPix = new QPixmap("img/sPlatform.gif");
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
	things.push_back(new Yoshi(yPix, 225, 390));
	
	//coin on stats panel (lava)
	sCoin = new Coin(coinPix, 170, 460);
	sCoin->setZValue(2);
	
	//heart
	heart = new Heart(hPix, 20, 465);
	heart->setZValue(2);
	
	/*create text*/
	//font size
	font.setPixelSize(30);
	
	//word "Score"
	sLabel = new QGraphicsSimpleTextItem("Score: ");
	sLabel->setPos(300, 460);
	sLabel->setFont(font);
	sLabel->setZValue(2);
	
	//actual score value
	score = 0;
	QString temp = QString::number(score);
	sAmount = new QGraphicsSimpleTextItem(temp);
	sAmount->setPos(400, 460);
	sAmount->setFont(font);
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
	
	
	//platforms (preset)
	platforms.push_back(new BPlatform(bpPix, 0, 50));
	platforms.push_back(new BPlatform(bpPix, 300, 50));
	platforms.push_back(new BPlatform(bpPix, 150, 150));
	platforms.push_back(new BPlatform(bpPix, 150, 350));
	platforms.push_back(new MPlatform(mpPix, 50, 250));
	platforms.push_back(new MPlatform(mpPix, 200, 250));
	platforms.push_back(new MPlatform(mpPix, 350, 250));
	platforms.push_back(new SPlatform(spPix, 0, 150));
	platforms.push_back(new SPlatform(spPix, 450, 150));
	platforms.push_back(new SPlatform(spPix, 0, 350));
	platforms.push_back(new SPlatform(spPix, 450, 350));
	
	//now barrage the scene with the items!
	gScene->addItem(background);
	gScene->addItem(heart);
	gScene->addItem(sCoin);
	gScene->addItem(sLabel);
	gScene->addItem(sAmount);
	gScene->addItem(lAmount);
	gScene->addItem(cAmount);
	for(int k=0; k<things.size(); k++)
		gScene->addItem(things[k]);
	
	for(int i=0; i<platforms.size(); i++)
		gScene->addItem(platforms[i]);
	
	
	//timers
	timer = t;
	
	//counters
	goombaCnt = 0;
	koopaCnt = 0;
	kamekCnt = 0;
	billCnt = 0;
	coinCnt = 0;
	
	//connect to slot functions
	connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newCoin()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newGoomba()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newKoopa()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newKamek()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newBill()));
	connect(timer, SIGNAL(timeout()), this, SLOT(offScreen()));
	
	//timer->start();
}

/****************************************************************/
/*destructor*/
Game::~Game()
{
	
}
