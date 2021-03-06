#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"
#include "pixie.h"
#include "boy.h"
#include "remembrance.h"
#include "exp.h"

class Remembrance;


class Bullet : public Pixie
{
public:
	Bullet(Boy* boy, Remembrance* r, Exp* e);
	~Bullet() {}
   	
	void update(float dt);	
	cocos2d::Sprite* getSprite() const {return sprite;}
	bool checkCollision(Exp* ex);
	void setPosition();
    	
private:
	cocos2d::Vec2 velocity;
	bool playSound;

	cocos2d::Size viewSize;
	cocos2d::Point origin;
	cocos2d::Sprite* sprite;
	int bulletWidth;
	cocos2d::Sprite* boyObj;
	Remembrance* remem;
	std::list<Pixie*>& pixList;
	Exp* explosion;	
};

#endif // __BULLET_H__
