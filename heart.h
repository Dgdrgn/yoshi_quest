#ifndef HEART_H
#define HEART_H
#include "thing.h"

/** A class for Heart objects
@author Jesus Garcia*/
class Heart : public Thing
{
	public:
		Heart(QPixmap *pm, int lx, int ly);
		~Heart();
		void move();
	private:
		/*Pixmap image*/
		QPixmap *heart;
};
#endif
