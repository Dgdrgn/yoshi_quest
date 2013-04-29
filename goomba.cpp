#include "goomba.h"

/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object
@param r Boolean that determines direction of movement*/
Goomba::Goomba(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = goombaEnemy;
	goomba1 = new QPixmap("img/goombaw1.gif");
	right = r;
	frame = 1;
}

/**Destructor*/
Goomba::~Goomba()
{
	delete goomba1;
}

/**Move function in Thing class*/
void Goomba::move() 
{
	if(locy+height < 450) {
		locy+=vely;
	}
	if(right)
		locx += velx*5;
	else
		locx -= velx*5;
	update();
}
