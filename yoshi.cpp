#include "yoshi.h"

Yoshi::Yoshi(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	right = true;
	yoshiCrouchR = new QPixmap("img/yoshic.jpg");
	yoshiCrouchL = new QPixmap("img/yoshicr.jpg");
	yoshiJumpR = new QPixmap("img/yoshij11.jpg");
	yoshiJumpL = new QPixmap("img/yoshij11r.jpg");
	yoshiAirR = new QPixmap("img/yoshij12.jpg");
	yoshiAirL = new QPixmap("img/yoshij12r.jpg");
	yoshiFallR = new QPixmap("img/yoshij13.jpg");
	yoshiFallL = new QPixmap("img/yoshij13r.jpg");
	yoshiWalk1R = new QPixmap("img/yoshiw1.jpg");
	yoshiWalk1L = new QPixmap("img/yoshiw1r.jpg");
	yoshiWalk2R = new QPixmap("img/yoshiw2.jpg");
	yoshiWalk2L = new QPixmap("img/yoshiw2r.jpg");
	yoshiWalk3R = new QPixmap("img/yoshiw3.jpg");
	yoshiWalk3L = new QPixmap("img/yoshiw3r.jpg");
}

Yoshi::~Yoshi()
{

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
}

void Yoshi::walk1()
{
	locx += 5;
	if(right) {
		setPixmap(*yoshiWalk1R);
		updateWH(yoshiWalk1R);
	}
	else {
		setPixmap(*yoshiWalk1L);
		updateWH(yoshiWalk1L);		
	}
	update();
}

void Yoshi::walk2()
{
	locx += 5;
	if(right) {
		setPixmap(*yoshiWalk2R);
		updateWH(yoshiWalk2R);
	}
	else {
		setPixmap(*yoshiWalk2L);
		updateWH(yoshiWalk2L);
	}
	update();
}

void Yoshi::walk3()
{
	locx += 5;
	if(right) {
		setPixmap(*yoshiWalk3R);
		updateWH(yoshiWalk3R);
	}
	else {
		setPixmap(*yoshiWalk3L);
		updateWH(yoshiWalk3L);
	}
	update();
}

void Yoshi::walk4()
{
	locx += 5;
	if(right) {
		setPixmap(*yoshiWalk2R);
		updateWH(yoshiWalk2R);
	}
	else {
		setPixmap(*yoshiWalk2L);
		updateWH(yoshiWalk2L);
	}
	update();
}

void Yoshi::jump()
{
	for(int i=0; i<20; i++) {
		if(right) {
			setPixmap(*yoshiJumpR);
			updateWH(yoshiJumpR);
			locx++;
		}
		else {
			setPixmap(*yoshiJumpL);
			updateWH(yoshiJumpL);
			locx--;
		}
		locy++;
		update();
	}
	setPixmap(*yoshiAirR);
	updateWH(yoshiAirR);
	update();
	for(int j=0; j<20; j++) {
		if(right) {
			setPixmap(*yoshiFallR);
			updateWH(yoshiFallR);
			locx++;
		}
		else {
			setPixmap(*yoshiFallL);
			updateWH(yoshiFallL);
			locx--;
		}
		locy--;
		update();
	}
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
}

void Yoshi::stop()
{
	idle();
}
