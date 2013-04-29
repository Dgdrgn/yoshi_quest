#include "magic.h"
#include <cmath>

Magic::Magic(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = ammo;
	right = r;
	frame = 1;
	magic = pm;
}

Magic::~Magic()
{

}

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
