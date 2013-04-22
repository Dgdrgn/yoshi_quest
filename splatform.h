#ifndef SPLATFORM_H
#define SPLATFORM_H
#include "platform.h"

class SPlatform : public Platform
{
	public:
		SPlatform(QPixmap *pm, int lx, int ly);
		~SPlatform();
		void move();
	private:
		QPixmap *sPlatform;
};
#endif
