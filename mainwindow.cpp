#include "mainwindow.h"
#include "iostream"
Main::Main()
{
	setWindowTitle("Yoshi's Quest");
	setFixedSize(WINDOW_MAX_X, WINDOW_MAX_Y);
	time = new QTimer(this);
	time->setInterval(100);
	n = "";
	sScreen = new Start;
	gScreen = new Game(time, n);
	setCentralWidget(sScreen);
	QWidget::layout()->setContentsMargins(0, 0, 0, 0);
	
	startG = new QPushButton("Start Game");
	pauseG = new QPushButton("Pause Game");
	quitG = new QPushButton("Quit Game");
	connect(startG, SIGNAL(clicked()), this, SLOT(start()));
	connect(pauseG, SIGNAL(clicked()), this, SLOT(pause()));
	connect(quitG, SIGNAL(clicked()), qApp, SLOT(quit()));
	
	name = new QTextEdit;
	name->setFixedWidth(100);
	name->setFixedHeight(25);
	name->setFontPointSize(8);
	name->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	info = new QTextEdit;
	info->setReadOnly(true);
	info->setFixedWidth(90);
	info->setFontPointSize(8);
	info->setPlainText("Instructions: Yoshi is on a quest! Use the WSAD keys to move Yoshi around to avoid the enemies. Collect coins for extra points. Collecting five coins or a heart will give Yoshi an extra life. When Yoshi loses all of his lives, its game over.");
	
	layout = new QVBoxLayout;
	layout->addWidget(name);
	layout->addWidget(info);
	layout->addWidget(startG);
	layout->addWidget(pauseG);
	layout->addWidget(quitG);
	
	dock = new QWidget;
	dock->setLayout(layout);
	
	dWidget = new QDockWidget;
	dWidget->setWidget(dock);
	dWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
	addDockWidget(Qt::RightDockWidgetArea, dWidget);
}

Main::~Main()
{
	//
}

/*void Main::game()
{

}
*/

void Main::pause()
{
	if(time->isActive())
		time->stop();
	else
		time->start();
}

void Main::start()
{
	n = name->toPlainText();
	if(n != "") {
		gScreen = new Game(time, n);
		switchGame();
		time->start();
	}
}

void Main::switchGame()
{
	layout->removeWidget(sScreen);
	layout->addWidget(gScreen);
	setCentralWidget(gScreen);
	show();
}

/****************************************************************/
/*Keyboard inputs*/
void Main::keyPressEvent(QKeyEvent *e)
{
	switch(e->key()) {
		case Qt::Key_D:
			gScreen->yoshiW1();
			break;
		case Qt::Key_A:
			gScreen->yoshiW2();
			break;
		case Qt::Key_W:
			gScreen->yoshiJ();
			break;
		case Qt::Key_S:
			gScreen->yoshiC();
			break;
		default:
			gScreen->yoshiI();
			break;
	}
}

void Main::keyReleaseEvent(QKeyEvent *e)
{
	gScreen->yoshiI();
}
