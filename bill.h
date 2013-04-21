#ifndef BILL_H
#define BILL_H
#include "thing.h"

class Bill : public Thing
{
	public:
		Bill(QPixmap *pm, int lx, int ly);
		~Bill();
};
#endif
