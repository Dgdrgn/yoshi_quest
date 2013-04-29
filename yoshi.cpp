#include "yoshi.h"
#include "iostream"

Yoshi::Yoshi(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	type = hero;
	right = true;
	frame = 1;
	yoshiCrouchR = new QPixmap("img/yoshic.gif");
	yoshiCrouchL = new QPixmap("img/yoshicr.gif");
	yoshiJumpR = new QPixmap("img/yoshij11.gif");
	yoshiJumpL = new QPixmap("img/yoshij11r.gif");
	yoshiWalk2R = new QPixmap("img/yoshiw2.gif");
	yoshiWalk2L = new QPixmap("img/yoshiw2r.gif");
}

Yoshi::~Yoshi()
{

}

void Yoshi::move()
{
	//does not automatically move
}

void Yoshi::idle()
{
	if(right) {
		setPixmap(*yoshiWalk2L);
		updateWH(yoshiWalk2L);
	}
	else {
		setPixmap(*yoshiWalk2R);
		updateWH(yoshiWalk2R);
	}
	update();
}

void Yoshi::walkR()
{
	locx+= velx*5;
	right = false;
	update();
}

void Yoshi::walkL()
{
	locx-=velx*5;
	right = true;
	update();
}

void Yoshi::jump()
{
	if(right) {
		setPixmap(*yoshiJumpL);
		updateWH(yoshiJumpL);
	}
	else {
		setPixmap(*yoshiJumpR);
		updateWH(yoshiJumpR);
	}
	locy-= 10;
	update();
}

void Yoshi::crouch()
{
	if(right) {
		setPixmap(*yoshiCrouchL);
		updateWH(yoshiCrouchL);
	}
	else {
		setPixmap(*yoshiCrouchR);
		updateWH(yoshiCrouchR);
	}
	locy+= 10;
	update();
}

void Yoshi::stop()
{
	idle();
}
