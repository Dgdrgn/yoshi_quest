#include "heart.h"

/**Constructor
@param pm A pointer for the pixmap image
@param lx The x location of the object
@param ly The y location of the object*/
Heart::Heart(QPixmap *pm, int lx, int ly, int vx, int vy) : Thing(pm, lx, ly, vx, vy)
{
	type = life;
	heart = new QPixmap("img/heart.png");
	right = false;
	frame = 0;
}

/**Destructor*/
Heart::~Heart()
{
	delete heart;
}

/**Move fuction from Thing class*/
void Heart::move()
{
	//does not move
}
