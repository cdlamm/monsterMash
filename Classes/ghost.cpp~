#include <iostream>
#include <cmath>
#include "ghost.h"
#include "SimpleAudioEngine.h"

Ghost::Ghost():
	velocity(200, 200),
	playSound(false),
	viewSize(cocos2d::Director::getInstance()->getVisibleSize()),
	origin(cocos2d::Director::getInstance()->getVisibleOrigin()),
	sprite(cocos2d::Sprite::create("spirit.png")),
	ghostWidth(sprite->getContentSize().width)
{
	int newX = rand() % 1024 + origin.x;
	int newY = rand() % 768 + origin.y;
	sprite->setPosition(cocos2d::Point(newX,newY));
}

void Ghost::update(float dt)
{
	cocos2d::Vec2 position = sprite->getPosition();
	cocos2d::Vec2 incr = velocity * dt;
	sprite->setPosition(position.x + incr.x, position.y + incr.y);

	cocos2d::Point location = sprite->getPosition();

	if(location.x > viewSize.width - ghostWidth/2){
		velocity.x = -abs(velocity.x);

	}
	else if(location.x < ghostWidth/2){
		velocity.x = abs(velocity.x);

	}
	else if ( location.y > viewSize.height - ghostWidth/2 ) {
		velocity.y = -abs(velocity.y);

  	}
  	else if ( location.y < ghostWidth/2 ) {
    		velocity.y = abs(velocity.y);
    			
    	}
}









