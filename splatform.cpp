#include "splatform.h"

SPlatform::SPlatform(QPixmap *pm, int lx, int ly) : Platform(pm, lx, ly)
{
	sPlatform = new QPixmap("img/sPlatform.jpg");
	cnt = 0;
}

SPlatform::~SPlatform()
{

}

void SPlatform::move()
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
