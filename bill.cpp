#include "bill.h"
/**
Constructor
@param pm A pointer to the pixmap image. 
@param lx The x location of the image.
@param ly The y location of the image.
@param r A boolean that tells whether it is facing right or left
*/
Bill::Bill(QPixmap *pm, int lx, int ly, int vx, int vy, bool r) : Thing(pm, lx, ly, vx, vy)
{
	type = billEnemy;
	bill = pm;
	right = r;
	frame = 0;
}

/**
Destructor
*/
Bill::~Bill()
{
	delete bill;
}

/**Move function from inherited Thing class*/
void Bill::move(int x, int y)
{
	x++;
	y++;
	if(right) {
		locx -= velx*5;
	}
	else {
		locx += velx*5;
	}
	update();
}
