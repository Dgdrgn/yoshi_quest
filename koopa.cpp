#include "koopa.h"

Koopa::Koopa(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = koopaEnemy;
	koopa1L = new QPixmap("img/koopaw1.gif");
	koopa2L = new QPixmap("img/koopaw2.gif");
	koopa1R = new QPixmap("img/koopaw1r.gif");
	koopa2R = new QPixmap("img/koopaw2r.gif");
	frame = 1;
	right = r;
}

Koopa::~Koopa()
{
	delete koopa1L;
	delete koopa2L;
	delete koopa1R;
	delete koopa2R;
}

void Koopa::move()
{
	if(frame == 1) {
		if(right) 
			setPixmap(*koopa1R);
		else
			setPixmap(*koopa1L);
		frame++;
	}
	else {
		if(right)
			setPixmap(*koopa2R);
		else
			setPixmap(*koopa2L);
		frame = 1;
	}
	if(right)
		locx+=5;
	else
		locx-=5;
	update();
	cnt++;
}
