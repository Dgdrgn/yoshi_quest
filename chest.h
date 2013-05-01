#ifndef CHEST_H
#define CHEST_H
#include "thing.h"

/**
A class for a treasure chest object.

@author Jesus Garcia
*/
class Chest : public Thing
{
	public:
		Chest(QPixmap *pm, int lx, int ly, int vx, int vy, bool right);
		~Chest();
		void move();
		void moveIt(int pX, int pY);
	private:
		/**Pointer to the pixmap image*/
		QPixmap *chest;
};
#endif
