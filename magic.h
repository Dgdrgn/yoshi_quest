#ifndef MAGIC_H
#define MAGIC_H
#include "thing.h"

class Magic : public Thing
{
	public:
		Magic(QPixmap *pm, int lx, int ly);
		~Magic();
};
#endif
