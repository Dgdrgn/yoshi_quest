#include "mainwindow.h"
#include "iostream"

/**Constructor for main window. Creates the layout of the main window*/
Main::Main()
{
	setWindowTitle("Yoshi's Quest");
	setFixedSize(WINDOW_MAX_X, WINDOW_MAX_Y);
	time = new QTimer(this);
	time->setInterval(50);
	n = "";
	sScreen = new Start;
	gScreen = new Game(time, n);
	setCentralWidget(sScreen);
	
	startG = new QPushButton("Start Game");
	pauseG = new QPushButton("Pause Game");
	quitG = new QPushButton("Quit Game");
	connect(startG, SIGNAL(clicked()), this, SLOT(start()));
	connect(pauseG, SIGNAL(clicked()), this, SLOT(pause()));
	connect(quitG, SIGNAL(clicked()), qApp, SLOT(quit()));
	
	name = new QTextEdit;
	name->setFixedWidth(180);
	name->setFixedHeight(25);
	name->setFontPointSize(8);
	name->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	info = new QTextEdit;
	info->setReadOnly(true);
	info->setFixedWidth(180);
	info->setFontPointSize(12);
	info->setPlainText("Instructions: Yoshi is on a quest for treasure! Use the WSAD keys to move Yoshi around to avoid the enemies. Collect the treasure chest to complete each level. Collect coins for extra points. Collecting five coins or a heart will give Yoshi an extra life. When Yoshi loses all of his lives, its game over. Note: To start the game, please enter your name above and press start. To reset, press start again.");
	
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

	gMusic = new QSound("img/mp.wav");
	gMusic->setLoops(-1);
	connect(time, SIGNAL(timeout()), this, SLOT(musicPlay()));
}
/**Destructor*/
Main::~Main()
{
	
}
/**Pauses the game*/
void Main::pause()
{
	if(time->isActive()) {
		time->stop();
	}
	else {
		time->start();
	}
}
/**Starts the game*/
void Main::start()
{
	n = name->toPlainText();
	if(n != "") {
		gScreen = new Game(time, n);
		switchGame();
		time->start();
	}
}
/**Switches from the start screen to the game screen*/
void Main::switchGame()
{
	layout->removeWidget(sScreen);
	layout->addWidget(gScreen);
	setCentralWidget(gScreen);
	show();
}

/**Reads keys that are pressed*/
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

/**Reads keys that are released*/
void Main::keyReleaseEvent(QKeyEvent *e)
{
	gScreen->yoshiI();
}

/**Controls music*/
void Main::musicPlay()
{
	if(time->isActive()) {
		if(gMusic->isFinished()) {
			gMusic->play();
		}
	}
	else {
		gMusic->stop();
	}
}
