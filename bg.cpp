#include "bg.h"

/**
Constructor
@param pm A pointer to the pixmap image. 
@param lx The x location of the image.
@param ly The y location of the image.
*/
Bg::Bg(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	type = other;
	back = new QPixmap("img/bg.png");
}

/**
Destructor
*/
Bg::~Bg()
{
	delete back;
}

/**
Move function from inherited Thing class
*/
void Bg::move()
{
	//doesn't move
}
