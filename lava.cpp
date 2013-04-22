#include "lava.h"

Lava::Lava(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	lava1 = new QPixmap("img/lava1.jpg");
	lava2 = new QPixmap("img/lava2.jpg");
	lava3 = new QPixmap("img/lava3.jpg");
	lavas = 1;
}

Lava::~Lava()
{

}

void Lava::move()
{
	switch(lavas) {
		case 1:
			setPixmap(*lava2);
			lavas = 2;
			break;
		case 2:
			setPixmap(*lava3);
			lavas = 3;
			break;
		case 3:
			setPixmap(*lava1);
			lavas = 1;
			break;
	}
}
