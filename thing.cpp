#include "thing.h"

Thing::Thing(QPixmap *pm, int lx, int ly)
{
	pixMap = pm;
	setPixmap(*pm);
	locx = lx;
	locy = ly;
	setPos(locx, locy);
}

Thing::~Thing()
{

}
