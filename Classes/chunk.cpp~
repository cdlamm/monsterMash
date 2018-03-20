#include <iostream>
#include <cmath>
#include "chunk.h"

Chunk::Chunk( cocos2d::Layer* p, const std::string name, float lx, float ly, float vx, float vy, int ox, int oy, int w, int h):
  Pixie(),
  layer(p),
  sprite( cocos2d::Sprite::create(name, cocos2d::Rect(ox, oy, w, h))),
  size( sprite->getContentSize().width, sprite->getContentSize().height ),
  velocity(cocos2d::Vec2(vx,vy))
{
  p->addChild(sprite,2);
  sprite->setPosition( cocos2d::Point(lx, ly) ); 
}

void Chunk::update(float dt) {
  cocos2d::Point position = sprite->getPosition();
  cocos2d::Vec2 incr = velocity * dt;
  sprite->setPosition(position.x + incr.x, position.y + incr.y );
}

float Chunk::getDistance( const Pixie* b ) const {
  return sprite->getPosition().distanceSquared(b->getSprite()->getPosition());
}
