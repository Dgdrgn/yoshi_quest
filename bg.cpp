#include "bg.h"

Bg::Bg(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	back = new QPixmap("img/bg.jpg");
	cnt = 0;
}

Bg::~Bg()
{
	delete back;
}

void Bg::move()
{
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
