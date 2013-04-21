#ifndef HEART_H
#define HEART_H
#include "thing.h"

class Heart : public Thing
{
	public:
		Heart(QPixmap *pm, int lx, int ly);
		~Heart();
		void move();
};
#endif
