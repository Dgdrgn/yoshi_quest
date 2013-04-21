#ifndef KAMEK_H
#define KAMEK_H
#include "thing.h"

class Kamek : public Thing
{
	public:
		Kamek(QPixmap *pm, int lx, int ly);
		~Kamek();
};
#endif
