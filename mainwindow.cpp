#include "mainwindow.h"
#include "iostream"
Main::Main()
{
	time = new QTimer(this);
	sScreen = new Start;
	gScreen = new Game();
	createActions();
	createMenus();
	layout = new QVBoxLayout;
	window = new QWidget;
	window->setWindowTitle("Yoshi's Quest");
	window->setFixedSize(WINDOW_MAX_X, WINDOW_MAX_Y);
	setCentralWidget(sScreen);
	//setFocusPolicy(Qt::StrongFocus);
	menuBar()->show();
	layout->addWidget(gScreen);
	setFocus();
	std::cout << "has focus" << hasFocus() << std::endl;
}

Main::~Main()
{
	delete sScreen;
	delete window;
}

void Main::show()
{
	window->setLayout(layout);
	window->show();
}

/*void Main::game()
{

}

void Main::pause()
{

}

void Main::start()
{

}*/

void Main::createActions()
{
	exitAct = new QAction("&Exit", this);
	exitAct->setStatusTip("&Exit Game");
	connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void Main::createMenus()
{
	fileMenu = menuBar()->addMenu("&File");
	fileMenu->addAction(exitAct);
}

void Main::keyPressEvent(QKeyEvent *e)
{
	std::cout << e->key() << std::endl;
	switch(e->key()) {
		case Qt::Key_Left:
			gScreen->yLeft();
			break;
		case Qt::Key_Right:
			gScreen->yRight();
			break;
		case Qt::Key_Up:
			gScreen->yUp();
			break;
		case Qt::Key_Down:
			gScreen->yDown();
			break;
		case Qt::Key_Space:
			switchGame();
			break;
	}
}

void Main::keyReleaseEvent(QKeyEvent *e)
{
	switch(e->key()) {
		case Qt::Key_Left:
			gScreen->yStop();
			break;
		case Qt::Key_Right:
			gScreen->yStop();
			break;
		case Qt::Key_Up:
			gScreen->yStop();
			break;
		case Qt::Key_Down:
			gScreen->yStop();
			break;
	}
}

void Main::switchGame()
{
	std::cout << "HI" << std::endl;
	layout->removeWidget(sScreen);
	layout->addWidget(gScreen);
	setCentralWidget(gScreen);
	show();
}
