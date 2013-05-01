#include "chompball.h"
/**
Constructor
@param pm A pointer to the pixmap image. 
@param lx The x location of the image.
@param ly The y location of the image.
@param r A boolean that tells whether it is facing right or left
*/
ChompBall::ChompBall(QPixmap *pm, int lx, int ly, int vx, int vy, bool r) : Thing(pm, lx, ly, vx, vy)
{
	type = other;
	chompball = new QPixmap("img/chompball.png");
	right = r;
	frame = 0;
}

/**
Destructor
*/
ChompBall::~ChompBall()
{
	delete chompball;
}

void ChompBall::move()
{
	locx += velx*5;
	locy += vely*5;
	update();
}

/**Move function from inherited Thing class*/
void ChompBall::moveIt(int pX, int pY)
{
	velx = (pX-locx)/10;
	vely = (pY-locy)/10;
}
