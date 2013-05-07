#include "yoshi.h"
#include "iostream"

/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object*/
Yoshi::Yoshi(QPixmap *pm, int lx, int ly, int vx, int vy) : Thing(pm, lx, ly, vx, vy)
{
	type = hero;
	right = false;
	frame = 1;
	yoshiCrouchR = new QPixmap("img/yoshij13.png");
	yoshiCrouchL = new QPixmap("img/yoshij13r.png");
	yoshiJumpR = new QPixmap("img/yoshij11.png");
	yoshiJumpL = new QPixmap("img/yoshij11r.png");
	yoshiWalk2R = new QPixmap("img/yoshiw2.png");
	yoshiWalk2L = new QPixmap("img/yoshiw2r.png");
}

/**Destructor*/
Yoshi::~Yoshi()
{

}

/**Move function from Thing class*/
void Yoshi::move(int x, int y)
{
	x++;
	y++;
	//does not automatically move
}

/**Switches frame when Yoshi does not move*/
void Yoshi::idle()
{
	if(locy+height < 445) {
		if(right) {
			setPixmap(*yoshiCrouchL);
			updateWH(yoshiCrouchL);
		}
		else {
			setPixmap(*yoshiCrouchR);
			updateWH(yoshiCrouchR);
		}
	}
	if(locy+height >= 445) {
		if(right) {
			setPixmap(*yoshiWalk2L);
			updateWH(yoshiWalk2L);
		}
		else {
			setPixmap(*yoshiWalk2R);
			updateWH(yoshiWalk2R);
		}
	}
	update();
}

/**Makes Yoshi swim right*/
void Yoshi::walkR()
{
	if(locx+width < 500) {
		locx+= velx*5;
		right = false;
		update();
	}
}

/**Makes Yoshi swim left*/
void Yoshi::walkL()
{
	if(locx > 0) {
		locx-=velx*5;
		right = true;
		update();
	}
}

/**Makes Yoshi swim up*/
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
	if(locy > 0) {
		locy-= 10;
		update();
	}
}

/**Makes Yoshi swim down*/
void Yoshi::crouch()
{
	if(locy+height < 450) {
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
}

/**Yoshi stops moving*/
void Yoshi::stop()
{
	idle();
}
