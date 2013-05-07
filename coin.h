#ifndef COIN_H
#define COIN_H
#include "thing.h"

/**
A class for coins

@author Jesus Garcia
*/
class Coin : public Thing
{
	public:
		Coin(QPixmap *pm, int lx, int ly, int vx, int vy);
		~Coin();
		void move(int x, int y);
	private:
		/**A pointer to the pixmap image*/
		QPixmap *coin;
};
#endif
