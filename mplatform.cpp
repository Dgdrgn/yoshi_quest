#include "mplatform.h"

MPlatform::MPlatform(QPixmap *pm, int lx, int ly) : Platform(pm, lx, ly)
{
	mPlatform = new QPixmap("img/mPlatform.jpg");
	cnt = 0;
}

MPlatform::~MPlatform()
{

}

void MPlatform::move()
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
