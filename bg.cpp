#include "bg.h"

Bg::Bg(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	type = other;
	back = new QPixmap("img/bg.jpg");
	cnt = 0;
}

Bg::~Bg()
{
	delete back;
}

void Bg::move()
{
	//doesn't move
}
