#include "bplatform.h"

BPlatform::BPlatform(QPixmap *pm, int lx, int ly) : Platform(pm, lx, ly)
{
	bPlatform = new QPixmap("img/bPlatform.gif");
	cnt = 0;
}

BPlatform::~BPlatform()
{

}
