#include "kamek.h"
/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object
@param r Boolean that determines direction of movement*/
Kamek::Kamek(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	changeFrame = 0;
	type = kamekEnemy;
	frame = 1;
	right = r;
	if(r) {
		kamek1 = pm;
		kamek2 = new QPixmap("img/kamek2.gif");
		kamek3 = new QPixmap("img/kamek3.gif");
	}
	else {
		kamek1 = pm;
		kamek2 = new QPixmap("img/kamek22.gif");
		kamek3 = new QPixmap("img/kamek23.gif");
	}
	del = false;
}
/**Destructor*/
Kamek::~Kamek()
{
	delete kamek1;
	delete kamek2;
	delete kamek3;
}
/**Move function from Thing class*/
void Kamek::move()
{
	if(frame == 1) {
		changeFrame++;
		if(changeFrame == 4) {
			setPixmap(*kamek2);
			frame++;
			changeFrame = 0;
		}
	}
	else if(frame == 2) {
		changeFrame++;
		if(changeFrame == 4) {
			setPixmap(*kamek3);
			frame++;
			changeFrame = 0;
		}
	}
	else if(frame == 3){
		changeFrame++;
		if(changeFrame == 4) {
			setPixmap(*kamek1);
			frame++;
			changeFrame = 0;
		}
	}
	else {
		changeFrame++;
		if(changeFrame == 4)
			del = true;
	}
	update();
}
