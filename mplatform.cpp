#include "mplatform.h"

MPlatform::MPlatform(QPixmap *pm, int lx, int ly) : Platform(pm, lx, ly)
{
	mPlatform = new QPixmap("img/mPlatform.gif");
	cnt = 0;
}

MPlatform::~MPlatform()
{

}
