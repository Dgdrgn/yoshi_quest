#include "mainwindow.h"
/*#include "gamewindow.h"
#include "startwindow.h"
#include "pausewindow.h"*/

Main::Main()
{
	time = new QTimer;
	window = new QWidget;
	window->setWindowTitle("12");
	mb = menuBar();
	createActions();
	createMenus();
}

Main::~Main()
{
	
	window->show();
}

void Main::show()
{
	
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
	exitAct = new QAction("Exit", this);
	exitAct->setStatusTip(tr("Exit Game"));
	connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void Main::createMenus()
{
	fileMenu = new QMenu("File", this);
	mb->addMenu(fileMenu);
	fileMenu->addAction(exitAct);
}
