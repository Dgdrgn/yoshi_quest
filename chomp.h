#ifndef CHOMP_H
#define CHOMP_H
#include "thing.h"

/**
A class for a chain chomp object.

@author Jesus Garcia
*/
class Chomp : public Thing
{
	public:
		Chomp(QPixmap *pm, int lx, int ly, int vx, int vy, bool right);
		~Chomp();
		void move();
		void moveIt(int pX, int pY);
	private:
		/**Pointers to the pixmap images*/
		QPixmap *chompl;
		QPixmap *chompr;
};
#endif
