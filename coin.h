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
		Coin(QPixmap *pm, int lx, int ly);
		~Coin();
		void move();
	private:
		/**A pointer to the pixmap image*/
		QPixmap *coin;
};
#endif
