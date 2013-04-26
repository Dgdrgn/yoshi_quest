#include "goomba.h"

Goomba::Goomba(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	type = goombaEnemy;
	goomba1 = new QPixmap("img/goombaw1.gif");
	goomba2 = new QPixmap("img/goombaw2.gif");
	right = true;
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
	if(cnt == 10000) {
		vely++;
		cnt = 0;
	}
	locy += vely;
	if(locy >= 680)
		locy = -680;
	if(locx+width >= 500)
		right = false;
	else if(locx <= 0)
		right = true;
	if(right)
		locx += 5;
	else
		locx -= 5;
	update();
	cnt++;
}
