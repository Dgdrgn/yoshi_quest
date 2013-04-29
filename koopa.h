#ifndef KOOPA_H
#define KOOPA_H
#include "thing.h"

class Koopa : public Thing
{
	public:
		Koopa(QPixmap *pm, int lx, int ly, bool r);
		~Koopa();
		void move();
	private:
		QPixmap *koopa1L;
		QPixmap *koopa1R;
};
#endif
