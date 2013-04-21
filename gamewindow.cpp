#include "gamewindow.h"

void Game::animate()
{
	background->move();
	background2->move();
}

Game::Game(QTimer *time)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	gScene = new QGraphicsScene();
	setScene(gScene);
	yPix = new QPixmap("img/yoshiw2.jpg");
	bPix = new QPixmap("img/bg.jpg");
	background = new Bg(bPix, 0, 0);
	background2 = new Bg(bPix, 0, -680);
	yoshi = new Yoshi(yPix, 300, 300);
	gScene->addItem(background);
	gScene->addItem(background2);
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
