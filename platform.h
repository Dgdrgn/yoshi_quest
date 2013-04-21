#ifndef PLATFORM_H
#define PLATFORM_H
#include "thing.h"

class Platform : public Thing
{
	public:
		Platform(QPixmap *pm, int lx, int ly);
		~Platform();
};
#endif
