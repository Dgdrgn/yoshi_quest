#ifndef BPLATFORM_H
#define BPLATFORM_H
#include "platform.h"

class BPlatform : public Platform
{
	public:
		BPlatform(QPixmap *pm, int lx, int ly);
		~BPlatform();
		void move();
	private:
		QPixmap *bPlatform;
};
#endif
