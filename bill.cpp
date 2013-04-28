#include "bill.h"

Bill::Bill(QPixmap *pm, int lx, int ly, bool r) : Thing(pm, lx, ly)
{
	type = billEnemy;
	bill = pm;
	right = r;
	frame = 0;
}

Bill::~Bill()
{
	delete bill;
}

void Bill::move()
{
	if(right) {
		locx -= 20;
	}
	else {
		locx += 20;
	}
	update();
	cnt++;
}
