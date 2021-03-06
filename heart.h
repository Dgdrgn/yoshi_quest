#ifndef HEART_H
#define HEART_H
#include "thing.h"

/** A class for Heart objects
@author Jesus Garcia*/
class Heart : public Thing
{
	public:
		Heart(QPixmap *pm, int lx, int ly, int vx, int vy);
		~Heart();
		void move(int x, int y);
	private:
		/*Pixmap image*/
		QPixmap *heart;
};
#endif
