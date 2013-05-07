#ifndef WIND_H
#define WIND_H
#include "thing.h"
/** A class for wind objects
@author Jesus Garcia*/
class Wind : public Thing
{
	public:
		Wind(QPixmap *pm, int lx, int ly, int vx, int vy, bool r);
		~Wind();
		void move(int x, int y);
	private:
		/**Pixmap images*/
		QPixmap *wind;
};
#endif
