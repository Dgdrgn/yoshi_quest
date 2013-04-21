#ifndef LAVA_H
#define LAVA_H
#include "thing.h"

class Lava : public Thing
{
	public:
		Lava(QPixmap *pm, int lx, int ly);
		~Lava();
		void move();
};
#endif
