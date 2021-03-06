#ifndef YOSHI_H
#define YOSHI_H
#include "thing.h"

/**A class for the Yoshi object
@author Jesus Garcia*/
class Yoshi : public Thing
{
	public:
		Yoshi(QPixmap *pm, int lx, int ly, int vx, int vy);
		~Yoshi();
		void move(int x, int y);
		void idle();
		void walkR();
		void walkL();
		void jump();
		void crouch();
		void stop();
	
	private:
		/**Pixmap images*/
		QPixmap *yoshiCrouchR;
		QPixmap *yoshiCrouchL;
		QPixmap *yoshiJumpR;
		QPixmap *yoshiJumpL;
		QPixmap *yoshiAirR;
		QPixmap *yoshiAirL;
		QPixmap *yoshiFallR;
		QPixmap *yoshiFallL;
		QPixmap *yoshiWalk2R;
		QPixmap *yoshiWalk2L;
};
#endif
