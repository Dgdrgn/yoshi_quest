#include "kamek.h"

Kamek::Kamek(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = kamekEnemy;
	frame = 1;
	right = r;
	if(r) {
		kamek1 = pm;
		kamek2 = new QPixmap("img/kamek2.gif");
		kamek3 = new QPixmap("img/kamek3.gif");
	}
	else {
		kamek1 = pm;
		kamek2 = new QPixmap("img/kamek22.gif");
		kamek3 = new QPixmap("img/kamek23.gif");
	}
}

Kamek::~Kamek()
{
	delete kamek1;
	delete kamek2;
	delete kamek3;
}

void Kamek::move()
{
	if(frame == 1) {
		setPixmap(*kamek2);
		frame++;
	}
	else if(frame == 2) {
		setPixmap(*kamek3);
		frame++;
	}
	else
		setPixmap(*kamek1);
	if(cnt == 10000) {
		vely++;
		cnt = 0;
	}
	locy += vely;
	if(locy >= 680)
		locy = -680;
	update();
	cnt++;
}
