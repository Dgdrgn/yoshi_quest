#include "wind.h"
#include <cmath>
/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object
@param r Boolean that determines direction of movement*/
Wind::Wind(QPixmap *pm, int lx, int ly, int vx, int vy, bool r) : Thing(pm, lx, ly, vx, vy)
{
	type = ammo;
	right = r;
	frame = 1;
	wind = pm;
}
/**Destructor*/
Wind::~Wind()
{

}
/**Move function from Thing class*/
void Wind::move(int x, int y)
{
	if(right)
		velx += 2;
	else
		velx -= 2;
	vely = (y-locy)/15;
	locx += velx;
	locy += vely;
	update();
	cnt++;
	if(cnt >= 200)
		del = true;
}
