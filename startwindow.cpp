#include "startwindow.h"

/**Constructor*/
Start::Start()
{
	setFixedSize(500, 500);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	sScene = new QGraphicsScene();
	setScene(sScene);
	sMenu = new QGraphicsPixmapItem(QPixmap("img/start.jpg"));
	sScene->addItem(sMenu);
}

/**Destructor*/
Start::~Start()
{
	delete sMenu;
	delete sScene;
}
