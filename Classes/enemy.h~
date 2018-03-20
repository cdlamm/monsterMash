#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "cocos2d.h"
#include "pixie.h"

class Enemy : public Pixie
{
public:
	Enemy(cocos2d::Layer* p, const std::string name, const float lx, 
        const float ly);
        Enemy(cocos2d::Layer* p, const std::string name, const float lx, 
          const float ly, const float vx, const float vy);
	~Enemy(){}
   	
	void update(float dt);	
	cocos2d::Sprite* getSprite() const {return sprite;}

        cocos2d::Vec2 getPos() const {return sprite->getPosition(); }
	int getPositionX() {return sprite->getPosition().x;}
	int getPositionY() {return sprite->getPosition().y;}
        cocos2d::Vec2 getVelocity() const {return velocity;}
        void setVelocity( const cocos2d::Vec2& v) {velocity.set(v);}
        float getDistance(const Pixie* p) const;
        bool isExplode() { return false; }
	cocos2d::Size getViewSize(){return viewSize;}
    	
private:
	cocos2d::Vec2 velocity;
	bool playSound;

	cocos2d::Size viewSize;
	cocos2d::Point origin;
	cocos2d::Sprite* sprite;
	int enemyWidth;
        int enemyHeight;
};

#endif // __Ghost_H__
