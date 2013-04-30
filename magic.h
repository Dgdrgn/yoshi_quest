#ifndef MAGIC_H
#define MAGIC_H
#include "thing.h"
/** A class for magic objects
@author Jesus Garcia*/
class Magic : public Thing
{
	public:
		Magic(QPixmap *pm, int lx, int ly, int vx, int vy, bool r);
		~Magic();
		void move();
	private:
		/**Pixmap images*/
		QPixmap *magic;
};
#endif
