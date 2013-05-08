#include "mainwindow.h"
#include <fstream>
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
	newActions();
	newMenus();
	
	//retrieve current scores
	ifstream file;
	file.open("scores.txt");
	while(file.good()) {
		ScorePair* pair = new ScorePair;
		file >> pair->name;
		file >> pair->sc;
		highSc.push_back(pair);
	}
	selectionSort();
	file.close();
}
/**Destructor*/
Main::~Main()
{
	if(gScreen->overG) {
		ScorePair* pair = new ScorePair;
		pair->name = n.toStdString();
		pair->sc = gScreen->score;
		int highS = -1;
		if(!highSc.empty())
			int highS = highSc[0]->sc;
		int pairSc = pair->sc;
		if(highSc.size() > 10 && highS < pairSc) {
			highSc.pop_front();
			highSc.push_back(pair);
			selectionSort();
		}
		else if(highSc.size() <= 10) {
			highSc.push_back(pair);
			selectionSort();
		}
	}
	ofstream file;
	file.open("scores.txt");
	for(int i=0; i<10; i++) {
		if(!highSc.empty()) {
			//file << (highSc[i]->name) << " " << (highSc[i]->sc) << endl;
			//highSc.pop_front();
		}
		else
			break;
	}
	file.close();
}
/**Sorts high scores*/
void Main::selectionSort() {
	for(int i=0; i<9; i++) {
		int min = i;
		for(int j= i+1; j<10; j++) {
			if(highSc[j] < highSc[min]) {
				min = j;
			}
		}
		swap(highSc[i], highSc[min]);
	}
}
/**Pauses the game*/
void Main::pauseGame()
{
	if(time->isActive()) {
		time->stop();
	}
	else if(gScreen->overG == false) {
		time->start();
	}
}
/**Starts the game*/
void Main::startG()
{
	if(gScreen->overG) {
		ScorePair* pair = new ScorePair;
		pair->name = n.toStdString();
		pair->sc = gScreen->score;
		int highS = -1;
		if(!highSc.empty())
			int highS = highSc[0]->sc;
		int pairSc = pair->sc;
		if(highSc.size() > 10 && highS < pairSc) {
			highSc.pop_front();
			highSc.push_back(pair);
			selectionSort();
		}
		else if(highSc.size() <= 10) {
			highSc.push_back(pair);
			selectionSort();
		}
	}
	n = name->text();
	if(n != "") {
		star->close();
		gScreen = new Game(time, n);
		switchGame();
		time->start();
	}
	else {
		QWidget* user = new QWidget;
		QVBoxLayout *l = new QVBoxLayout;
	
		user->setWindowTitle("Yoshi's Quest: Username");
		user->setFixedSize(200, 500);
	
		QTextEdit *i = new QTextEdit;
		i->setReadOnly(true);
		i->setFixedWidth(180);
		i->setFontPointSize(12);
		i->setPlainText("Please enter your username.");
		l->addWidget(i);

		user->setLayout(l);
		user->show();
	}
}
/**Window to enter name*/
void Main::startGame()
{
	star = new QWidget;
	QVBoxLayout *l = new QVBoxLayout;
		
	star->setWindowTitle("Enter Username");
	star->setFixedSize(200, 100);
		
	name = new QLineEdit;
	name->setFixedWidth(180);
	name->setFixedHeight(25);
	name->setMaxLength(10);
	l->addWidget(name);
	
	QPushButton *st = new QPushButton("Start");
	connect(st, SIGNAL(clicked()), this, SLOT(startG()));
	l->addWidget(st);
	
	star->setLayout(l);
	star->show();
}
/**Shows the high scores*/
void Main::highScores()
{
	QWidget* high = new QWidget;
	QVBoxLayout *l = new QVBoxLayout;
	
	high->setWindowTitle("Yoshi's Quest: High Scores");
	high->setFixedSize(200, 500);
	
	
	
	QTextEdit *i = new QTextEdit;
	i->setReadOnly(true);
	i->setFixedWidth(180);
	i->setFontPointSize(12);
	i->setPlainText("Hello");
	l->addWidget(i);

	high->setLayout(l);
	high->show();
}
/**Shows the instructions for the game*/
void Main::instruct() 
{
	QWidget* instructions = new QWidget;
	QVBoxLayout *l = new QVBoxLayout;
	
	instructions->setWindowTitle("Yoshi's Quest: Instructions");
	instructions->setFixedSize(300, 200);
	
	QTextEdit *i = new QTextEdit;
	i->setReadOnly(true);
	i->setFixedWidth(280);
	i->setFontPointSize(12);
	i->setPlainText("Yoshi is on a quest for treasure! Help Yoshi obtain the treasure as he avoids enemies. Collecting coins gives your score a boost while a heart gives you a life. Everything else makes you lose a life.");
	l->addWidget(i);

	instructions->setLayout(l);
	instructions->show();
}
/**Shows the controls for the game*/
void Main::keyControls() 
{
	QWidget* controls = new QWidget;
	QGraphicsScene *s = new QGraphicsScene;
	QGraphicsView *v = new QGraphicsView(s);
	QVBoxLayout *l = new QVBoxLayout;
	
	controls->setWindowTitle("Yoshi's Quest: Controls");
	controls->setFixedSize(300, 300);
	
	QPixmap *pix = new QPixmap("img/wasd.jpg");
	QPixmap px = pix->scaled(170, 150);
	QGraphicsPixmapItem *cntrls = new QGraphicsPixmapItem(px);
	s->addItem(cntrls);
	l->addWidget(v);
	
	QTextEdit *i = new QTextEdit;
	i->setReadOnly(true);
	i->setFixedWidth(280);
	i->setFontPointSize(12);
	i->setPlainText("Use the WSAD keys to move Yoshi around to avoid the enemies and to collect coins for extra points.");
	l->addWidget(i);

	controls->setLayout(l);
	controls->show();
}
/**Switches from the start screen to the game screen*/
void Main::switchGame()
{
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
		case Qt::Key_Space:
			pauseGame();
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

/**Creates new actions for the menus*/
void Main::newActions()
{
	start = new QAction("&Start Game", this);
	pause = new QAction("&Pause Game", this);
	quit = new QAction("&Quit Game", this);
	high = new QAction("&High Scores", this);
	instructions = new QAction("&Instructions", this);
	controls = new QAction("&Controls", this);
	
	connect(start, SIGNAL(triggered()), this, SLOT(startGame()));
	connect(pause, SIGNAL(triggered()), this, SLOT(pauseGame()));
	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(high, SIGNAL(triggered()), this, SLOT(highScores()));
	connect(instructions, SIGNAL(triggered()), this, SLOT(instruct()));
	connect(controls, SIGNAL(triggered()), this, SLOT(keyControls()));
	
}
/**Creates new menus for the menu bar*/
void Main::newMenus()
{
	file = menuBar()->addMenu("&File");
	file->addAction(start);
	file->addAction(pause);
	file->addAction(quit);
	options = menuBar()->addMenu("&Option");
	options->addAction(high);
	help = menuBar()->addMenu("&Help");
	help->addAction(instructions);
	help->addAction(controls);
}
