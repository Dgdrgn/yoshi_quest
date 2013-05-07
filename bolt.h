#ifndef BOLT_H
#define BOLT_H
#include "thing.h"
/** A class for bolt objects
@author Jesus Garcia*/
class Bolt : public Thing
{
	public:
		Bolt(QPixmap *pm, int lx, int ly, int vx, int vy, bool r);
		~Bolt();
		void move(int x, int y);
	private:
		/**Pixmap images*/
		QPixmap *bolt;
};
#endif
