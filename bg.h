#ifndef BG_H
#define BG_H
#include "thing.h"
/**
A class for the background image

@author Jesus Garcia
*/
class Bg : public Thing
{
	public:
		Bg(QPixmap *pm, int lx, int ly, int vx, int vy);
		~Bg();
		void move();
	private:
		/**A pointer to the pixmap image*/
		QPixmap *back;
};
#endif
