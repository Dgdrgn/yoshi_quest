#include "startwindow.h"

Start::Start()
{
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	sScene = new QGraphicsScene();
	setScene(sScene);
	sMenu = new QGraphicsPixmapItem(QPixmap("img/start.gif"));
	sScene->addItem(sMenu);
}

Start::~Start()
{
	delete sMenu;
	delete sScene;
}
