#include "bg.h"

/**
Constructor
@param pm A pointer to the pixmap image. 
@param lx The x location of the image.
@param ly The y location of the image.
*/
Bg::Bg(QPixmap *pm, int lx, int ly, int vx, int vy) : Thing(pm, lx, ly, vx, vy)
{
	type = other;
	back = new QPixmap("img/bg.png");
	back2 = new QPixmap("img/bg2.png");
	back3 = new QPixmap("img/bg3.png");
	frame = 1;
}

/**
Destructor
*/
Bg::~Bg()
{
	delete back;
}

/**
Move function from inherited Thing class. Changes background for each level.
*/
void Bg::move(int x, int y)
{
	x++;
	y++;
	switch(frame-1) {
		case 0:
			setPixmap(*back2);
			frame++;
			break;
		case 1:
			setPixmap(*back3);
			frame++;
			break;
		case 2:
			setPixmap(*back);
			frame = 1;
			break;
	}
}
