#ifndef __GHOST_H__
#define __GHOST_H__

#include "cocos2d.h"
#include "pixie.h"

class Ghost : public Pixie
{
public:
	Ghost();
	~Ghost(){}
   	
	void update(float dt);	
	cocos2d::Sprite* getSprite() const {return sprite;}
    	
private:
	cocos2d::Vec2 velocity;
	bool playSound;

	cocos2d::Size viewSize;
	cocos2d::Point origin;
	cocos2d::Sprite* sprite;
	int ghostWidth;
};

#endif // __Ghost_H__
