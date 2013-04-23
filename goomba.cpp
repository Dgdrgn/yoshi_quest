#include "goomba.h"

Goomba::Goomba(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	goomba1 = new QPixmap("img/goombaw1.jpg");
	goomba2 = new QPixmap("img/goombaw2.jpg");
	bool right = true;
	bool pix1 = true;
}

Goomba::~Goomba()
{

}

void Goomba::move() {
	if(pix1) {
		setPixmap(*goomba2);
	}
	else {
		setPixmap(*goomba1);
	}
	if(pix1)
		pix1 = false;
	else
		pix1 = true;
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
		locx++;
	else
		locx--;
	update();
	cnt++;
}
