#include "goomba.h"

Goomba::Goomba(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = goombaEnemy;
	goomba1 = new QPixmap("img/goombaw1.gif");
	goomba2 = new QPixmap("img/goombaw2.gif");
	right = r;
	frame = 1;
}

Goomba::~Goomba()
{
	delete goomba1;
	delete goomba2;
}

void Goomba::move() 
{
	if(frame == 1) {
		setPixmap(*goomba2);
		frame++;
	}
	else {
		setPixmap(*goomba1);
		frame = 1;
	}
	if(right)
		locx += 5;
	else
		locx -= 5;
	update();
	cnt++;
}
