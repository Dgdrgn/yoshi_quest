#include "heart.h"

Heart::Heart(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	type = other;
	heart = new QPixmap("img/heart.gif");
	right = false;
	frame = 0;
}

Heart::~Heart()
{
	delete heart;
}

void Heart::move()
{
	//does not move
}
