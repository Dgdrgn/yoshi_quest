#include "heart.h"

Heart::Heart(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	heart = new QPixmap("img/heart.gif");
}

Heart::~Heart()
{
	delete heart;
}

void Heart::move()
{
	//does not move
}
