#include "thing.h"

/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object*/
Thing::Thing(QPixmap *pm, int lx, int ly, int vx, int vy)
{
	pixMap = pm;
	setPixmap(*pm);
	locx = lx;
	locy = ly;
	setPos(locx, locy);
	velx = vx;
	vely = vy;
	width = pm->width();
	height = pm->height();
	cnt = 0;
	del = false;
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
