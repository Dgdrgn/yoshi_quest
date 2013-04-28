#include "platform.h"

Platform::Platform(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	type = floor;
	frame = 0;
	right = false;
}

Platform::~Platform()
{

}

void Platform::move()
{
	//does not move
}
