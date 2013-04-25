#ifndef KOOPA_H
#define KOOPA_H
#include "thing.h"

class Koopa : public Thing
{
	public:
		Koopa(QPixmap *pm, int lx, int ly);
		~Koopa();
		void move();
	private:
		QPixmap *koopa1L;
		QPixmap *koopa2L;
		QPixmap *koopa1R;
		QPixmap *koopa2R;
		bool pix1;
		bool right;
};
#endif
