#ifndef KOOPA_H
#define KOOPA_H
#include "thing.h"

class Koopa : public Thing
{
	public:
		Koopa(QPixmap *pm, int lx, int ly);
		~Koopa();
};
#endif
