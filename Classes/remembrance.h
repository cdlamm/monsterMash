#ifndef __REMEMBRANCE_H__
#define __REMEMBRANCE_H__

#include "cocos2d.h"
#include "boy.h"
#include "ghost.h"
#include "pixie.h"
#include "bullet.h"
#include "background.h"
#include "exp.h"

class Bullet;

class Remembrance : public cocos2d::Layer
{
public:
  Remembrance();
  ~Remembrance();
  static cocos2d::Scene* createScene();
  bool init();
  /*static Remembrance& getInstance()
  {
    static Remebrance* rememInstance;
    return rememInstance;
  }
  */
  virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
  //virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
  //virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
  //virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
  virtual bool checkAvailable() {return false;}

  std::list<Bullet*> getBulletList(){return bulletList;}
  //void deleteBullet(Bullet* b);
 // void checkBullets();



  void update(float);
    
  // a selector callback
  void menuCloseCallback(cocos2d::Ref* pSender);
  bool getCollision(Exp* ex, Pixie* p);
  void makechunks(std::list<Pixie*>::iterator it);
  float getDistance( const Pixie* p ) const;
  std::list<Pixie*>& getPixieList(){return myPixies;}
  int& getBulletCount(){return bulletCount;}
  void decrementBulletCount(){--bulletCount;}
  void shootBullets();
  void incrementScore(){score++;}
  void setScoreLabel(){ scoreLabel =
    cocos2d::Label::createWithTTF(updateScore(),
	 "fonts/Marker Felt.ttf", 24);}
//cocos2d::Label* getScoreLabel(){return scoreLabel;}
  void addScoreLabel(){addChild(scoreLabel,1);}
  void removeScoreLabel(){removeChild(scoreLabel);}
  void retainScoreLabel(){scoreLabel->retain();}
  void setScoreLabelPosition(){scoreLabel->setPosition(100,750);}
  std::string updateScore();
  void updateObjectPool();
  void resetshowlist();
    
  // implement the "static create()" method manually
  CREATE_FUNC(Remembrance);

private:

  float moveTime;
  float dx, dy;

  void generateGhosts();
  void generateBullet();

  Boy* boy;
  Exp* explosion;
  
  cocos2d::Label* shootingLabel;
  cocos2d::Label* freeLabel;
  cocos2d::Label* showLabel;
  std::list<Pixie*> myPixies; 
  std::list<Bullet*> bulletList;
  int bulletCount;
  int maxBullets;
  int score;
  cocos2d::Size visibleSize;
  cocos2d::Point origin;

  Background* trees;
  Background* wall;
  Background* snow;
  Background* ground;

  cocos2d::Label* scoreLabel;

  bool updated = false;
};

#endif // __REMEMBRANCE_H__
