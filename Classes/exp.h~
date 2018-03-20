#ifndef EXP__H
#define EXP__H
#include "cocos2d.h"
#include "enemy.h"
#include "chunk.h"
#include <cstring>
#include <list>

/*
 *  Exp is the sprite that could explode.
 *  Using object pool manages chunks.
 *  This is a simple version. It has a timer to explode 
 *  every 1s. It seperate the car sprite into 16 pieces.
 *  
 *   
 */

class Exp : public Enemy {
public:
    Exp(cocos2d::Layer*p, const std::string name, const float lx, const float ly);
    Exp(cocos2d::Layer*p, const std::string name, const float lx, const float ly,
      const float vx, const float vy );
    virtual ~Exp();
    void virtual update(float);
    cocos2d::Sprite* getSprite() const { return Enemy::getSprite(); }
    
    float getDistance( const Pixie* b ) const ;
    cocos2d::Vec2 getPos() const { return Enemy::getPos(); }
    void makechunks();
    void resetshowlist();
    void setExplode(bool flag) {explode = flag;}
    bool getExplode() { return explode; }
    int getFreeList() { return freelist.size(); }
    int getShowList() { return showlist.size(); }
 
private:
  std::list<Pixie*> showlist;
  std::list<Pixie*> freelist;
  float count;
  bool explode;
  cocos2d::Layer* layer;
  int xVel;
};
#endif
