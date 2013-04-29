#include "goomba.h"

Goomba::Goomba(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = goombaEnemy;
	goomba1 = new QPixmap("img/goombaw1.gif");
	right = r;
	frame = 1;
}

Goomba::~Goomba()
{
	delete goomba1;
}

void Goomba::move() 
{
	if(right)
		locx += 5;
	else
		locx -= 5;
	update();
	cnt++;
}
