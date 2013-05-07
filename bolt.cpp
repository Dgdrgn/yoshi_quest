#include "bolt.h"
#include <cmath>
/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object
@param r Boolean that determines direction of movement*/
Bolt::Bolt(QPixmap *pm, int lx, int ly, int vx, int vy, bool r) : Thing(pm, lx, ly, vx, vy)
{
	type = ammo;
	right = r;
	frame = 1;
	bolt = pm;
}
/**Destructor*/
Bolt::~Bolt()
{

}
/**Move function from Thing class*/
void Bolt::move(int x, int y)
{
	velx = (x-locx)/20;
	vely = (y-locy)/20;
	locx += velx;
	locy += vely;
	update();
	cnt++;
	if(cnt >= 150)
		del = true;
}
