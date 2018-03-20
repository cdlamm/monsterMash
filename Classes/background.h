#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "cocos2d.h"

class Background : public cocos2d::Layer {
public:
  Background(int speed);
  ~Background(){}
  void update(float dt);
  virtual bool init(const std::string&);
  cocos2d::Sprite* stretchFit(cocos2d::Sprite* const sprite);
  static Background* create(const std::string&, int);
  void setScrollSpeed(int speed) { scrollSpeed = speed; }
  int getScrollSpeed() {return scrollSpeed;}
  void setBackgroundFile(const std::string& bf) { backFile = bf; }

private:
  cocos2d::Vec2 origin;
  cocos2d::Size viewSize;
  int scrollSpeed;
  std::string backFile;

  cocos2d::Sprite* bg1;
  cocos2d::Sprite* bg2;

};
