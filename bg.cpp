#include "bg.h"

Bg::Bg(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	back = new QPixmap("img/bg.jpg");
}

Bg::~Bg()
{
	delete back;
}

void Bg::move()
{
	if(cnt == 100) {
		vely++;
		cnt = 0;
	}
	locy += vely;
	update();
	cnt++;
}
