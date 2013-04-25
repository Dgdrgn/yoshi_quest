#include "kamek.h"

Kamek::Kamek(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	
}

Kamek::~Kamek()
{
	
}

void Kamek::move()
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
