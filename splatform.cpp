#include "splatform.h"

SPlatform::SPlatform(QPixmap *pm, int lx, int ly) : Platform(pm, lx, ly)
{
	sPlatform = new QPixmap("img/sPlatform.gif");
	cnt = 0;
}

SPlatform::~SPlatform()
{

}
