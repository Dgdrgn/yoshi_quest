#ifndef CHOMPBALL_H
#define CHOMPBALL_H
#include "thing.h"

/**
A class for a bullet bill object.

@author Jesus Garcia
*/
class ChompBall : public Thing
{
	public:
		ChompBall(QPixmap *pm, int lx, int ly, int vx, int vy, bool right);
		~ChompBall();
		void move();
		void moveIt(int pX, int pY);
	private:
		/**A pointer to the pixmap image*/
		QPixmap *chompball;
};
#endif
