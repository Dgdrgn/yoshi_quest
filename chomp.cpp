#include "chomp.h"
/**
Constructor
@param pm A pointer to the pixmap image. 
@param lx The x location of the image.
@param ly The y location of the image.
@param r A boolean that tells whether it is facing right or left
*/
Chomp::Chomp(QPixmap *pm, int lx, int ly, int vx, int vy, bool r) : Thing(pm, lx, ly, vx, vy)
{
	type = chompEnemy;
	chompl = new QPixmap("img/chomp.png");
	chompr = new QPixmap("img/chompr.png");
	right = r;
	frame = 0;
}

/**
Destructor
*/
Chomp::~Chomp()
{
	delete chompl;
	delete chompr;
}

void Chomp::move()
{
	locx += velx*5;
	locy += vely*5;
	if(velx < 0)
		setPixmap(*chompr);
	else
		setPixmap(*chompl);
	update();
}

/**Move function from inherited Thing class*/
void Chomp::moveIt(int pX, int pY)
{
	velx = (pX-locx)/10;
	vely = (pY-locy)/10;
	move();
}
