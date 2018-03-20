#ifndef CHUNK__H
#define CHUNK__H
#include "cocos2d.h"
#include "pixie.h"
#include <cstring>

/*
 *  Chunk is general sprite.
 *
 */

class Chunk : public Pixie {
public:
  Chunk(cocos2d::Layer* p, const std::string name, float lx, float ly, float vx, float vy, int ox, int oy, int w, int h);
  virtual ~Chunk() { layer -> removeChild(sprite); }
  void virtual update(float);
  cocos2d::Sprite* getSprite() const { return sprite; }
  cocos2d::Vec2 getVelocity() const {return velocity;}
  void setVelocity( const cocos2d::Vec2& v) {velocity.set(v);}
  float getDistance( const Pixie* b ) const ;
  cocos2d::Vec2 getPos() const { return sprite->getPosition(); }
  bool isExplode() { return false; }
private:
  cocos2d::Layer* layer;
  cocos2d::Sprite* sprite;
  cocos2d::Vec2 size;
  cocos2d::Vec2 velocity;
};
#endif
