#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>

class Thing : public QGraphicsPixmapItem
{
	public:
		Thing(QPixmap *pm, int lx, int ly);
		~Thing();
		virtual void move() = 0;
	private:
		int locx;
		int locy;
		int width;
		int height;
		int velx;
		int vely;
		QPixmap *pixMap;
};
#endif
