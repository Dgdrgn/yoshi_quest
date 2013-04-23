#ifndef GOOMBA_H
#define GOOMBA_H
#include "thing.h"

class Goomba : public Thing
{
	public:
		Goomba(QPixmap *pm, int lx, int ly);
		~Goomba();
		void move();
	private:
		QPixmap *goomba1;
		QPixmap *goomba2;
		bool right;
		bool pix1;
};
#endif
