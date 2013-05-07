#ifndef KAMEK_H
#define KAMEK_H
#include "thing.h"
/** A class for Kamek objects
@author Jesus Garcia*/
class Kamek : public Thing
{
	public:
		Kamek(QPixmap *pm, int lx, int ly, int vx, int vy, bool r);
		~Kamek();
		void move(int x, int y);
	private:
		/**Pixmap items*/
		QPixmap *kamek1;
		QPixmap *kamek2;
		QPixmap *kamek3;
		/**Integer that determines frame changes*/
		int changeFrame;
};
#endif
