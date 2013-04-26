#ifndef MAGIC_H
#define MAGIC_H
#include "thing.h"

class Magic : public Thing
{
	public:
		Magic(QPixmap *pm, int lx, int ly, bool r);
		~Magic();
		void move();
	private:
		QPixmap *magic;
		QPixmap *magic2;
		QPixmap *magic3;
		QPixmap *magic4;
};
#endif
