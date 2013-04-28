#include "magic.h"

Magic::Magic(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = ammo;
	right = r;
	frame = 1;
	magic = pm;
	magic2 = new QPixmap("img/magic2.gif");
	magic3 = new QPixmap("img/magic3.gif");
	magic4 = new QPixmap("img/magic4.gif");
}

Magic::~Magic()
{

}

void Magic::move()
{
	if(!right) {
		locx -= 20;
		switch(frame) {
			case 1:
				setPixmap(*magic4);
				frame++;
				break;
			case 2:
				setPixmap(*magic3);
				frame++;
				break;
			case 3:
				setPixmap(*magic2);
				frame++;
				break;
			case 4:
				setPixmap(*magic);
				frame = 1;
				break;
		}
	}
	else {
		locx += 20;
		switch(frame) {
			case 1:
				setPixmap(*magic2);
				frame++;
				break;
			case 2:
				setPixmap(*magic3);
				frame++;
				break;
			case 3:
				setPixmap(*magic4);
				frame++;
				break;
			case 4:
				setPixmap(*magic);
				frame = 1;
				break;
		}
	}
	update();
}
