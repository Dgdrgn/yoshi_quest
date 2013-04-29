#include "thing.h"

/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object*/
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

/**Destructor*/
Thing::~Thing()
{

}

/**Updates the image on the screen*/
void Thing::update()
{
	setPos(locx, locy);
}
