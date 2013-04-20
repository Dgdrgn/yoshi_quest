#ifndef COIN_H
#define COIN_H
#include "thing.h"

class Coin : public Thing
{
	public:
		Coin(QPixmap *pm, int lx, int ly);
		~Coin();
		void move();
};
#endif
