#include "gamewindow.h"

void Game::animate()
{
	background->move();
	background2->move();
	lava->move();
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

Game::Game(QTimer *time)
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
	background = new Bg(bPix, 0, 0);
	background2 = new Bg(bPix, 0, -680);
	yoshi = new Yoshi(yPix, 225, 225);
	heart = new Heart(hPix, 20, 460);
	heart->setZValue(2);
	lava = new Lava(lPix, 0, 451);
	lava->setZValue(1);
	Platform *tempP = new BPlatform(bpPix, 50, 400);
	platforms.push_back(tempP);
	gScene->addItem(background);
	gScene->addItem(background2);
	gScene->addItem(lava);
	gScene->addItem(heart);
	gScene->addItem(yoshi);
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
	timer = time;
	timer->setInterval(5);
	connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
	timer->start();
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
