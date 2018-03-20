#include <iostream>
#include <cmath>
#include "enemy.h"
#include "SimpleAudioEngine.h"

Enemy::Enemy(cocos2d::Layer* p, const std::string name, const float lx, const float ly):
	velocity(0, 0),
	playSound(false),
	viewSize(cocos2d::Director::getInstance()->getVisibleSize()),
	origin(cocos2d::Director::getInstance()->getVisibleOrigin()),
	sprite(cocos2d::Sprite::create(name)),
	enemyWidth(sprite->getContentSize().width),
        enemyHeight(sprite->getContentSize().height)
{
	p->addChild(sprite,1);
	sprite->setPosition(cocos2d::Point(lx,ly));
}
Enemy::Enemy(cocos2d::Layer* p, const std::string name, const float lx, 
  const float ly, const float vx, const float vy):
	velocity(vx, vy),
	playSound(false),
	viewSize(cocos2d::Director::getInstance()->getVisibleSize()),
	origin(cocos2d::Director::getInstance()->getVisibleOrigin()),
	sprite(cocos2d::Sprite::create(name)),
	enemyWidth(sprite->getContentSize().width),
        enemyHeight(sprite->getContentSize().height)
{
	p->addChild(sprite,1);
	sprite->setPosition(cocos2d::Point(lx,ly));
}

void Enemy::update(float dt)
{
	cocos2d::Vec2 position = sprite->getPosition();
	cocos2d::Vec2 incr = velocity * dt;
	sprite->setPosition(position.x + incr.x, position.y + incr.y);

	cocos2d::Point location = sprite->getPosition();
	if ( location.y > 400 ) {
		velocity.y = -abs(velocity.y);
		
  	}
  	else if ( location.y < enemyHeight/2 ) {
    		velocity.y = abs(velocity.y);    		
  	} 	
}

float Enemy::getDistance(const Pixie* p) const {
  return sprite->getPosition().distanceSquared(p ->getSprite()->getPosition());
}







