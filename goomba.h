#ifndef GOOMBA_H
#define GOOMBA_H
#include "thing.h"

class Goomba : public Thing
{
	public:
		Goomba(QPixmap *pm, int lx, int ly, bool r);
		~Goomba();
		void move();
	private:
		QPixmap *goomba1;
		QPixmap *goomba2;
};
#endif
