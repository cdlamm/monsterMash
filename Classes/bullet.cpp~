#include <iostream>
#include <cmath>
#include "bullet.h"
#include "SimpleAudioEngine.h"

Bullet::Bullet(Boy* boy, Remembrance* r, Exp* ex): 
	velocity(0, 0),
	playSound(false),
	viewSize(cocos2d::Director::getInstance()->getVisibleSize()),
	origin(cocos2d::Director::getInstance()->getVisibleOrigin()),
	sprite(cocos2d::Sprite::create("snowball.png")),
	bulletWidth(sprite->getContentSize().width),
	boyObj(boy->getSprite()),
	remem(r),
	pixList(remem->getPixieList()),
	explosion(ex)

{
		sprite->setPosition(cocos2d::Point(-200,0));
}

void Bullet::setPosition()
{
	int newX = boyObj->getPosition().x;
	int newY = boyObj->getPosition().y;
	if(boyObj->getScaleX() == 1.0)
	{
		velocity.x = 500;
		newX = newX + boyObj->getContentSize().width/2;

	}
	else
	{
		velocity.x = -500;
		newX = newX - boyObj->getContentSize().width/2;
	}
	
	sprite->setPosition(cocos2d::Point(newX,newY));
}
bool Bullet::checkCollision(Exp* ex)
{		
	
	int bulletWidth = sprite->getContentSize().width;
	int bulletHeight = sprite->getContentSize().height;
	int oWidth = ex->getSprite()->getContentSize().width;
	int oHeight = ex->getSprite()->getContentSize().height;

	cocos2d::Point bulletPos = sprite->getPosition();
	cocos2d::Point pixPos = ex->getSprite()->getPosition();

	if(bulletPos.x+bulletWidth/2 < pixPos.x-oWidth/2)
	{
		return false;
	}
	if(bulletPos.x-bulletWidth/2 > pixPos.x+oWidth/2)
	{
		return false;
	}
	if(bulletPos.y-bulletHeight/2 > pixPos.y+oHeight/2)
	{
		return false;
	}
	if(bulletPos.y+bulletHeight/2 < pixPos.y-oHeight/2)
	{
		return false;
	}
	
	return true;
}

void Bullet::update(float dt)
{
	cocos2d::Vec2 position = sprite->getPosition();
	cocos2d::Vec2 incr = velocity * dt;
	sprite->setPosition(position.x + incr.x, position.y + incr.y);

	cocos2d::Point location = sprite->getPosition();
	

	if(checkCollision(explosion) && explosion->getShowList() == 0)
	{
	CocosDenshion::SimpleAudioEngine::
		    	getInstance()->playEffect("audio/snowball.wav");
	    if(remem->getBulletCount() > 0)
		{
			remem->decrementBulletCount();
		}
		sprite->setPosition(cocos2d::Point(-200,0));
		explosion->setExplode(true);
		
		remem->incrementScore();
		remem->retainScoreLabel();
		remem->removeScoreLabel();
		remem->setScoreLabel();
		remem->setScoreLabelPosition();
		remem->addScoreLabel();	
	}

	if(location.x > viewSize.width - bulletWidth/2 || 
			location.x < bulletWidth/2)
	{
		if(remem->getBulletCount() > 0)
		{
			remem->decrementBulletCount();
		}
		sprite->setPosition(cocos2d::Point(-200,0));		
	}	
}









