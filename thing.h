#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>

class Thing : public QGraphicsPixmapItem
{
	public:
		Thing(QPixmap *pm, int lx, int ly);
		~Thing();
		void update();
		int getLocx() {return locx;};
		int getLocy() {return locy;};
		int getWidth() {return width;};
		int getHeight() {return height;};
	protected:
		int cnt;
		int locx;
		int locy;
		int width;
		int height;
		int velx;
		int vely;
		QPixmap *pixMap;
};
#endif
