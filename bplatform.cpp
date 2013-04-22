#include "bplatform.h"

BPlatform::BPlatform(QPixmap *pm, int lx, int ly) : Platform(pm, lx, ly)
{
	bPlatform = new QPixmap("img/bPlatform.jpg");
	cnt = 0;
}

BPlatform::~BPlatform()
{

}

void BPlatform::move()
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
