#include "coin.h"

/**
Constructor
@param pm A pointer to the pixmap image. 
@param lx The x location of the image.
@param ly The y location of the image.
*/
Coin::Coin(QPixmap *pm, int lx, int ly) : Thing(pm, lx, ly)
{
	type = item;
	coin = new QPixmap("img/coin.gif");
	frame = 0;
	right = false;
}

/**
Destructor
*/
Coin::~Coin()
{
	delete coin;
}

/**
Move function from inherited Thing class
void Coin::move()
{
	if(cnt == 10000) {
		vely++;
		cnt = 0;
	}
	locy += vely*2;
	update();
	cnt++;
}
