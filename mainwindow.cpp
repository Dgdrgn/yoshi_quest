#include "mainwindow.h"

Main::Main()
{
	time = new QTimer;
	sScreen = new Start;
	createActions();
	createMenus();
	layout = new QVBoxLayout;
	window = new QWidget;
	window->setWindowTitle("Yoshi's Quest");
	window->setFixedSize(WINDOW_MAX_X, WINDOW_MAX_Y);
	setCentralWidget(sScreen);
}

Main::~Main()
{
	delete sScreen;
	delete window;
}

void Main::show()
{
	menuBar()->show();
	layout->addWidget(sScreen);
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
