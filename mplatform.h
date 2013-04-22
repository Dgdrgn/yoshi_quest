#ifndef MPLATFORM_H
#define MPLATFORM_H
#include "platform.h"

class MPlatform : public Platform
{
	public:
		MPlatform(QPixmap *pm, int lx, int ly);
		~MPlatform();
		void move();
	private:
		QPixmap *mPlatform;
};
#endif
