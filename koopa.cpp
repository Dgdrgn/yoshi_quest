#include "koopa.h"
/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object
@param r Boolean that determines direction of movement*/
Koopa::Koopa(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = koopaEnemy;
	koopa1L = new QPixmap("img/koopaw1.gif");
	koopa1R = new QPixmap("img/koopaw1r.gif");
	frame = 1;
	right = r;
}
/**Destructor*/
Koopa::~Koopa()
{
	delete koopa1L;
	delete koopa1R;
}
/**Move function from Thing class*/
void Koopa::move()
{
	if(locy+height < 450)
		locy+=vely;
	if(right) {
		setPixmap(*koopa1R);
	}
	else {
		setPixmap(*koopa1L);
	}
	if(right)
		locx+=velx*5;
	else
		locx-=velx*5;
	update();
}
