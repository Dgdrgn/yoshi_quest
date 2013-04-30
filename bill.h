#ifndef BILL_H
#define BILL_H
#include "thing.h"

/**
A class for a bullet bill object.

@author Jesus Garcia
*/
class Bill : public Thing
{
	public:
		Bill(QPixmap *pm, int lx, int ly, int vx, int vy, bool right);
		~Bill();
		void move();
	private:
		/**A pointer to the pixmap image*/
		QPixmap *bill;
};
#endif
