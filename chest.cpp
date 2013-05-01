#include "chest.h"
/**
Constructor
@param pm A pointer to the pixmap image. 
@param lx The x location of the image.
@param ly The y location of the image.
@param r A boolean that tells whether it is facing right or left
*/
Chest::Chest(QPixmap *pm, int lx, int ly, int vx, int vy, bool r) : Thing(pm, lx, ly, vx, vy)
{
	type = chestItem;
	chest = new QPixmap("img/chest.png");
	right = r;
	frame = 0;
}

/**
Destructor
*/
Chest::~Chest()
{
	delete chest;
}

void Chest::move()
{
	locx += velx*5;
	locy += vely*5;
	update();
}

/**Move function from inherited Thing class*/
void Chest::moveIt(int pX, int pY)
{
	velx = (pX-locx)/10;
	vely = (pY-locy)/10;
}
