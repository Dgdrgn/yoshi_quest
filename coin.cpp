#include "coin.h"

Coin::Coin(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	type = item;
	coin = new QPixmap("img/coin.gif");
	frame = 0;
	right = false;
}

Coin::~Coin()
{
	delete coin;
}

void Coin::move()
{
	if(cnt == 10000) {
		vely++;
		cnt = 0;
	}
	locy += vely;
	if(locy >= 680)
		locy = -680;
	update();
	cnt++;
}
