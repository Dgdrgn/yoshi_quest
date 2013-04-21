#include "gamewindow.h"

void Game::animate()
{
	background->move();
}

Game::Game(QTimer *time)
{
	
	gScene = new QGraphicsScene();
	setScene(gScene);
	yPix = new QPixmap("img/yoshiw2.jpg");
	bPix = new QPixmap("img/bg.jpg");
	background = new Bg(bPix, 0, 0);
	yoshi = new Yoshi(yPix, 300, 300);
	gScene->addItem(background);
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
