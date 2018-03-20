#include <iostream>
#include <cmath>
#include "pixie.h"

cocos2d::Vector<cocos2d::SpriteFrame*> Pixie::getAnimation
(const char *format, int count,cocos2d::SpriteFrameCache* animcache) {
  cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
  char str[100];
  for(int i = 1; i < count; i++) {
    sprintf(str, format, i);
    animFrames.pushBack(animcache->getSpriteFrameByName(str));
  }
  return animFrames;
}
