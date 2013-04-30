#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>

/**Base class for all Things(enemies, items, players, etc.)
@author Jesus Garcia*/
class Thing : public QGraphicsPixmapItem
{
	public:
		Thing(QPixmap *pm, int lx, int ly, int vx, int vy);
		~Thing();
		void update();
		/** Moves the object depending on the object*/
		virtual void move() = 0;
		/**Enumeration for the type of Thing*/
		enum Type {
			hero,
			goombaEnemy,
			koopaEnemy,
			kamekEnemy,
			billEnemy,
			ammo,
			item,
			floor,
			other,
			life
		};
		/**Integer that determines frame image*/
		int frame;
		/**Boolean that determines direction*/
		bool right;
		/**Boolean that determines when to delete object (mainly for Kamek)*/
		bool del;
		/**Type of Thing*/
		Type type;
		
		/**Accessors and Mutators*/
		int getLocx() {return locx;};
		int getLocy() {return locy;};
		int getWidth() {return width;};
		int getHeight() {return height;};
		void setLocx(int lx) {locx = lx;};
		void setLocy(int ly) {locy = ly;};

		/**Updates width and height of Thing after frame is changed*/
		void updateWH(QPixmap *p) {width = p->width(); height = p->height();};
	protected:
		/**x location*/
		int locx;
		/**y location*/
		int locy;
		/**width*/
		int width;
		/**height*/
		int height;
		/**x velocity*/
		int velx;
		/**y velocity*/
		int vely;
		/**Pixmap image*/
		QPixmap *pixMap;
};
#endif
