#ifndef KAMEK_H
#define KAMEK_H
#include "thing.h"

class Kamek : public Thing
{
	public:
		Kamek(QPixmap *pm, int lx, int ly, bool r);
		~Kamek();
		void move();
	private:
		QPixmap *kamek1;
		QPixmap *kamek2;
		QPixmap *kamek3;
		int changeFrame;
};
#endif
