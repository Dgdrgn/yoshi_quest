#include "goomba.h"

/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object
@param r Boolean that determines direction of movement*/
Goomba::Goomba(QPixmap *pm, int lx, int ly, int vx, int vy, bool r) : Thing(pm, lx, ly, vx, vy)
{
	type = goombaEnemy;
	goomba1 = new QPixmap("img/goombaw1.png");
	right = r;
	frame = 1;
}

/**Destructor*/
Goomba::~Goomba()
{
	delete goomba1;
}

/**Move function in Thing class*/
void Goomba::move(int x, int y) 
{
	x++;
	y++;
	if(locy+height < 450) {
		locy+=vely;
	}
	if(right)
		locx += velx;
	else
		locx -= velx;
	update();
}
