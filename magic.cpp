#include "magic.h"
#include <cmath>
/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object
@param r Boolean that determines direction of movement*/
Magic::Magic(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = ammo;
	right = r;
	frame = 1;
	magic = pm;
}
/**Destructor*/
Magic::~Magic()
{

}
/**Move function from Thing class*/
void Magic::move()
{
	if(!right) {
		locx -= velx*10;
		locy += 10*sin(locx);
	}
	else {
		locx += velx*10;
		locy += 10*sin(locx);
	}
	update();
}
