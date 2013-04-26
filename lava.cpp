#include "lava.h"

Lava::Lava(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	type = other;
	lava1 = new QPixmap("img/lava1.gif");
	lava2 = new QPixmap("img/lava2.gif");
	lava3 = new QPixmap("img/lava3.gif");
	frame = 1;
	right = false;
}

Lava::~Lava()
{

}

void Lava::move()
{
	switch(frame) {
		case 1:
			setPixmap(*lava2);
			frame++;
			break;
		case 2:
			setPixmap(*lava3);
			frame++;
			break;
		case 3:
			setPixmap(*lava1);
			frame = 1;
			break;
	}
}
