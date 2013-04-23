#include "thing.h"

Thing::Thing(QPixmap *pm, int lx, int ly)
{
	pixMap = pm;
	setPixmap(*pm);
	locx = lx;
	locy = ly;
	setPos(locx, locy);
	velx = 1;
	vely = 1;
	width = pm->width();
	height = pm->height();
}

Thing::~Thing()
{

}

void Thing::update()
{
	setPos(locx, locy);
}
