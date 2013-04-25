#include "koopa.h"

Koopa::Koopa(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	koopa1L = new QPixmap("img/koopaw1.gif");
	koopa2L = new QPixmap("img/koopaw2.gif");
	koopa1R = new QPixmap("img/koopaw1r.gif");
	koopa2R = new QPixmap("img/koopaw2r.gif");
	pix1 = true;
	right = true;
}

Koopa::~Koopa()
{

}

void Koopa::move()
{
	if(pix1) {
		if(right) 
			setPixmap(*koopa1R);
		else
			setPixmap(*koopa1L);
	}
	else {
		if(right)
			setPixmap(*koopa2R);
		else
			setPixmap(*koopa2L);
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
