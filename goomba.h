#ifndef GOOMBA_H
#define GOOMBA_H
#include "thing.h"

class Goomba : public Thing
{
	public:
		Goomba(QPixmap *pm, int lx, int ly);
		~Goomba();
};
#endif
