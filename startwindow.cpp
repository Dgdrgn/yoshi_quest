#include "startwindow.h"

Start::Start()
{
	sScene = new QGraphicsScene();
	setScene(sScene);
	sMenu = new QGraphicsPixmapItem(QPixmap("img/start.jpg"));
	sScene->addItem(sMenu);
}

Start::~Start()
{
	delete sMenu;
	delete sScene;
}

/*void Start::keyPressEvent(QKeyEvent *e)
{
	switch(e->key()) {
		case Qt::Key_Space :
			
			break;
	}
}*/
