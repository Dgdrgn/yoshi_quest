#include "heart.h"

Heart::Heart(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	heart = new QPixmap("img/heart.jpg");
}

Heart::~Heart()
{
	delete heart;
}
