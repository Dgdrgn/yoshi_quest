#include "gamewindow.h"

/****************************************************************/
/*checks for collisions*/
void Game::collisions()
{
	bool getOut = false;
	for(int i=0; i<things.size(); i++) {
		/*platforms*/
		if(things[i]->type != Thing::item && things[i]->type != Thing::billEnemy) {
			for(int j=0; j<platforms.size(); j++) {
				//stay
				if(((things[i]->getHeight() + things[i]->getLocy()) == 
				platforms[j]->getLocy()) && (things[i]->getLocx() + 
				things[i]->getWidth() > platforms[j]->getLocx()) 
				&& ((things[i]->getLocx()) < (platforms[j]->getLocx() + 
				platforms[j]->getWidth()))) {
					getOut = true;
				}
				//fall
				else {
					getOut = false;
					things[i]->setLocy((things[i]->getLocy())+1);
					things[i]->update();
				}
				if(getOut) {
					break;
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
	
	//moves background
	background->move();
	background2->move();
	
	//animates lava
	lava->move();
	
	//moves all other things
	for(int l=0; l<things.size(); l++) {
		things[l]->move();
	}
	
	//moves all platforms
	for(int i=0; i<platforms.size(); i++)
		platforms[i]->move();
	
	//removes platforms that are out of screen and adds a new one
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
		gScene->addItem(platforms.back());
	}
}

/****************************************************************/
/*adds a new coin*/
void Game::newCoin()
{
	if(coinCnt >= 200) {
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
		things.push_back(new Goomba(goombaPix, randx, 0));
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
		things.push_back(new Koopa(koopaPix, randx, 0));
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
		int randy = rand()%300;
		if(randx <= 250)
			things.push_back(new Kamek(kamekLPix, randx, randy, 0));
		else
			things.push_back(new Kamek(kamekRPix, randx, randy, 1));
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
void Game::newMagic()
{
	for(int i=0; i<things.size(); i++) {
		if(things[i]->type == Thing::kamekEnemy) {
			if(things[i]->frame == 3) {
				if(things[i]->right) {
					int y = things[i]->getLocy();
					int x = things[i]->getLocx() - 28;
					things.push_back(new Magic(magicPix, x, y, 1));
					gScene->addItem(things.back());
				}
				else {
					int y = things[i]->getLocy();
					int x = things[i]->getLocx() + 3;
					things.push_back(new Magic(magicPix, x, y, 0));
					gScene->addItem(things.back());
				}
			}
		}
	}
}

/****************************************************************/
/*constructor of the game graphics view*/
Game::Game()
{
	//removes scroll bars
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	//creates a new scene and sets it in a fixed location
	gScene = new QGraphicsScene();
	gScene->setSceneRect(0, 0, 500, 500);
	setScene(gScene);
	
	//creates the Pixmaps of all the "things" for their constructors
	yPix = new QPixmap("img/yoshiw2.gif");
	bPix = new QPixmap("img/bg.gif");
	hPix = new QPixmap("img/heart.gif");
	lPix = new QPixmap("img/lava1.gif");
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
	background2 = new Bg(bPix, 0, -680);
	
	//adds Yoshi (playable character) to list
	things.push_back(new Yoshi(yPix, 125, 125));
	
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
	
	//lava (stats panel)
	lava = new Lava(lPix, 0, 451);
	lava->setZValue(1);
	
	//platforms (preset)
	platforms.push_back(new BPlatform(bpPix, 50, 400));
	platforms.push_back(new BPlatform(bpPix, 50, 300));
	platforms.push_back(new MPlatform(mpPix, 150, 200));
	platforms.push_back(new MPlatform(mpPix, 150, 100));
	platforms.push_back(new SPlatform(spPix, 200, 0));
	
	//now barrage the scene with the items!
	gScene->addItem(background);
	gScene->addItem(background2);
	gScene->addItem(lava);
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
	timer = new QTimer(this);
	timer->setInterval(50);
	
	//counters
	goombaCnt = 0;
	koopaCnt = 0;
	kamekCnt = 0;
	billCnt = 0;
	coinCnt = 0;
	
	//connect to slot functions
	connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
	connect(timer, SIGNAL(timeout()), this, SLOT(collisions()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newCoin()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newGoomba()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newKoopa()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newKamek()));
	connect(timer, SIGNAL(timeout()), this, SLOT(newBill()));
	
	timer->start();
}

/****************************************************************/
/*destructor*/
Game::~Game()
{
	delete gScene;
}
