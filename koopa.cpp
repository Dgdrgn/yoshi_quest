#include "koopa.h"

Koopa::Koopa(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = koopaEnemy;
	koopa1L = new QPixmap("img/koopaw1.gif");
	koopa1R = new QPixmap("img/koopaw1r.gif");
	frame = 1;
	right = r;
}

Koopa::~Koopa()
{
	delete koopa1L;
	delete koopa1R;
}

void Koopa::move()
{
	if(right) {
		setPixmap(*koopa1R);
	}
	else {
		setPixmap(*koopa1L);
	}
	if(right)
		locx+=5;
	else
		locx-=5;
	update();
	cnt++;
}
