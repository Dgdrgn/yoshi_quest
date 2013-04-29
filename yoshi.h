#ifndef YOSHI_H
#define YOSHI_H
#include "thing.h"

class Yoshi : public Thing
{
	public:
		Yoshi(QPixmap *pm, int lx, int ly);
		~Yoshi();
		void move();
		void idle();
		void walkR();
		void walkL();
		void jump();
		void crouch();
		void stop();
	
	private:
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
