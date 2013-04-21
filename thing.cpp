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
}

Thing::~Thing()
{

}

void Thing::update()
{
	setPos(locx, locy);
}
