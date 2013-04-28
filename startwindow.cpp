#include "startwindow.h"

Start::Start()
{
	sScene = new QGraphicsScene();
	sView = new QGraphicsView();
	sView->setScene(sScene);
	sMenu = new QGraphicsPixmapItem(QPixmap("img/start.gif"));
	sScene->addItem(sMenu);
	layout = new QVBoxLayout;
	layout->addWidget(sView);
	setLayout(layout);
	
}

Start::~Start()
{
	delete sMenu;
	delete sScene;
}
