#include "platform.h"

Platform::Platform(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	
}

Platform::~Platform()
{

}

void Platform::move()
{
	if(cnt == 10000) {
		vely++;
		cnt = 0;
	}
	locy += vely;
	if(locy >= 680)
		locy = -680;
	update();
	cnt++;
}
