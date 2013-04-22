#ifndef BG_H
#define BG_H
#include "thing.h"

class Bg : public Thing
{
	public:
		Bg(QPixmap *pm, int lx, int ly);
		~Bg();
		void move();
	private:
		QPixmap *back;
};
#endif
