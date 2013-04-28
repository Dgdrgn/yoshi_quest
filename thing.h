#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>

class Thing : public QGraphicsPixmapItem
{
	public:
		enum Type {
			hero,
			goombaEnemy,
			koopaEnemy,
			kamekEnemy,
			billEnemy,
			ammo,
			item,
			floor,
			other
		};
		int frame;
		bool right, del;
		Thing(QPixmap *pm, int lx, int ly);
		~Thing();
		void update();
		virtual void move() = 0;
		Type type;
		int getLocx() {return locx;};
		int getLocy() {return locy;};
		int getWidth() {return width;};
		int getHeight() {return height;};
		void setLocx(int lx) {locx = lx;};
		void setLocy(int ly) {locy = ly;};
		void updateWH(QPixmap *p) {width = p->width(); height = p->height();};
	protected:
		int cnt;
		int locx;
		int locy;
		int width;
		int height;
		int velx;
		int vely;
		int id;
		QPixmap *pixMap;
};
#endif
