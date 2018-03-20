#ifndef PIXIE_H
#define PIXIE_H
#include<iostream>
#include "cocos2d.h"

class Pixie
{
public:
	Pixie(){};
	virtual ~Pixie(){};

	virtual void update(float dt)=0;
	virtual cocos2d::Sprite* getSprite() const =0;
	cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation
	(const char* format, int count, cocos2d::SpriteFrameCache* cache);
};


#endif
