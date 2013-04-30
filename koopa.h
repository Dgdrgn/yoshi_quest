#ifndef KOOPA_H
#define KOOPA_H
#include "thing.h"
/** A class for Koopa objects
@author Jesus Garcia*/
class Koopa : public Thing
{
	public:
		Koopa(QPixmap *pm, int lx, int ly, int vx, int vy, bool r);
		~Koopa();
		void move();
	private:
		/**Pixmap images*/
		QPixmap *koopa1L;
		QPixmap *koopa1R;
};
#endif
