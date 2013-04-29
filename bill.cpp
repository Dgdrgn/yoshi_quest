#include "bill.h"
/**
Constructor
@param pm A pointer to the pixmap image. 
@param lx The x location of the image.
@param ly The y location of the image.
@param r A boolean that tells whether it is facing right or left
*/
Bill::Bill(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
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

/**Move function from inherited Thing class
void Bill::move()
{
	if(right) {
		locx -= velx*20;
	}
	else {
		locx += velx*20;
	}
	update();
	cnt++;
}
