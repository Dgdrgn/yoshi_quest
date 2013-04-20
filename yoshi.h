#ifndef YOSHI_H
#define YOSHI_H
#include "thing.h"

class Yoshi : public Thing
{
	public:
		Yoshi(QPixmap *pm, int lx, int ly);
		~Yoshi();
		void move();
};
#endif
