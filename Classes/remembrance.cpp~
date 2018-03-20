#include "remembrance.h"
#include "SimpleAudioEngine.h"

#define COCOS2d_DEBUG 1

Remembrance::Remembrance() : 
  moveTime(0.1), 
  dx(5), 
  dy(5),
  boy(NULL),
  myPixies(0),
  bulletList(0),
  bulletCount(0),
  maxBullets(10),
  score(0)
{ 
  	scoreLabel =  cocos2d::Label::createWithTTF(updateScore(), "fonts/Marker Felt.ttf", 24);
	scoreLabel->setPosition(100,750);
    addChild(scoreLabel,1);
  	freeLabel =  cocos2d::Label::createWithTTF("Freelist: ", "fonts/Marker Felt.ttf", 24);
	freeLabel->setPosition(47,725);
    addChild(freeLabel,1);
  	showLabel =  cocos2d::Label::createWithTTF("Show: ", "fonts/Marker Felt.ttf", 24);
	showLabel->setPosition(52,700);
    addChild(showLabel,1);

}
Remembrance::~Remembrance()
{
  std::list<Pixie*>::iterator iter = myPixies.begin();
  while(iter!=myPixies.end())
  {
    delete (*iter);
      ++iter;
  }	

  std::list<Bullet*>::iterator biter = bulletList.begin();
  while(biter!=bulletList.end())
  {
    delete (*biter);
    ++biter;
  }	
}

void Remembrance::update(float dt) {
 
  updateObjectPool();  

  if(boy->getSprite()->getPosition().x+
		boy->getSprite()->getContentSize().width/2 >=
		explosion->getSprite()->getPosition().x-
		explosion->getSprite()->getContentSize().width/2)
	{
		cocos2d::Label* lose = cocos2d::Label::
		createWithTTF("Uh Oh! You lost!", "fonts/Marker Felt.ttf", 58);

  		lose->setPosition(
			cocos2d::Vec2(512, 384));

  		addChild(lose, 2);

		pauseSchedulerAndActions();
		setTouchEnabled(false);
		boy->getSprite()->stopAllActions();
		CocosDenshion::SimpleAudioEngine::
		    	getInstance()->stopAllEffects();
	}	
  else if(score >= 5)
  {
	cocos2d::Label* win = cocos2d::Label::
	createWithTTF("Yay! You won!", "fonts/Marker Felt.ttf", 58);
	cocos2d::Label* dance = cocos2d::Label::
	createWithTTF("(Dance Party)", "fonts/Marker Felt.ttf", 35);


	win->setPosition(
		cocos2d::Vec2(512, 384));
	dance->setPosition(
		cocos2d::Vec2(512, 335));	

  	cocos2d::Sprite* danceSprite = cocos2d::Sprite::create	("dance.png");
	danceSprite->setPosition(512,385);
		
	addChild(danceSprite,3);
	addChild(win, 3);
	addChild(dance, 3);
 
	pauseSchedulerAndActions();
	setTouchEnabled(false);

  }
  explosion->update(dt);
  boy->update(dt);

  //Cassidy - update background
  trees->update(dt);
  wall->update(dt);
  snow->update(dt);
  ground->update(dt);

  //bool collided = false;
  std::list<Pixie*>::iterator iter = myPixies.begin();
  ++iter;
  //++iter;
  //bool updated = false;
  while(iter !=  myPixies.end())
  {		
    (*iter)->update(dt);	
	if(getCollision(explosion,(*iter)))
	{
		(*iter)->getSprite()->retain();
		removeChild((*iter)->getSprite());
		delete (*iter);
		iter = myPixies.erase(iter);
	
	}
	else
	{
    	++iter;
	}
  }

  if(!bulletList.empty())
  {	
    std::list<Bullet*>::iterator bulletIter = bulletList.begin();
    while(bulletIter !=  bulletList.end())
    {		
      if((*bulletIter)->getSprite()->getPosition().x > 0)
      {
	(*bulletIter)->update(dt);
      }
	bulletIter++;
    }
  }

  	
}

cocos2d::Scene* Remembrance::createScene()
{
    // 'scene' is an autorelease object
    cocos2d::Scene* scene = cocos2d::Scene::create();
    
    // 'layer' is an autorelease object
    cocos2d::Layer* layer = Remembrance::create();

	//layerInstance = layer;
	//layerInstance = layer;
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void Remembrance::updateObjectPool(){
	std::stringstream strm;
	strm << "Freelist: ";
	strm << explosion->getFreeList();
	std::string freeStr = strm.str();
	freeLabel->retain();
	removeChild(freeLabel);
	freeLabel =
    cocos2d::Label::createWithTTF(freeStr,
	 "fonts/Marker Felt.ttf", 24);
    addChild(freeLabel, 1);
	freeLabel->setPosition(47,725);
	strm.clear();
 	strm.str("");
	strm << "Showlist: ";
	strm << explosion->getShowList();
	std::string showStr = strm.str();
	showLabel->retain();
	removeChild(showLabel);
	showLabel =
    cocos2d::Label::createWithTTF(showStr,
	 "fonts/Marker Felt.ttf", 24);
    addChild(showLabel, 1);
	showLabel->setPosition(52,700);
}

bool Remembrance::getCollision(Exp* ex, Pixie* pix)
{		
	if(ex->getSprite()->getZOrder() != pix->getSprite()->getZOrder()){
		return false;
	}
	
	int bWidth = ex->getSprite()->getContentSize().width;
	int bHeight = ex->getSprite()->getContentSize().height;
	int eWidth = pix->getSprite()->getContentSize().width;
	int eHeight = pix->getSprite()->getContentSize().height;

	cocos2d::Point bPos = ex->getSprite()->getPosition();
	cocos2d::Point ePos = pix->getSprite()->getPosition();

	if(bPos.x+bWidth/2 < ePos.x-eWidth/2)
	{
		return false;
	}
	if(bPos.x-bWidth/2 > ePos.x+eWidth/2)
	{
		return false;
	}
	if(bPos.y-bHeight/2 > ePos.y+eHeight/2)
	{
		return false;
	}
	if(bPos.y+bHeight/2 < ePos.y-eHeight/2)
	{
		return false;
	}
	
	return true;
}
void Remembrance::generateGhosts()
{
	for(int k = 0; k < 8; k++)
	{
		myPixies.push_back(new Ghost);
	}
}

void Remembrance::generateBullet()
{
	for(int k = 0; k < 10; k++)
	{
		Bullet* bullet = new Bullet(boy, this, explosion);
		bulletList.push_back(bullet);
		std::list<Bullet*>::iterator pixs = bulletList.end();
		pixs--;
		addChild((*pixs)->getSprite(),1);
	}
}
void Remembrance::shootBullets()
{
	if(bulletCount < maxBullets)
	{		
		std::list<Bullet*>::iterator pixs = bulletList.begin();
		std::advance(pixs,bulletCount);
		(*pixs)->setPosition();	
		bulletCount++;
	}

}
bool Remembrance::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	shootBullets();
	return true;
}

std::string Remembrance::updateScore()
{
	std::stringstream strm;
	strm << "Enemies Eliminated: ";
	strm << score;
	std::string scoreT = strm.str();
	return scoreT;
}
// on "init" you need to initialize your instance
bool Remembrance::init()
{
    //////////////////////////////
    // 1. super init first
  if ( !Layer::init() )
  {
    return false;
  }
    
  //Cassidy - create background for parallax scrolling
  trees = Background::create("trees.png",4);
  addChild(trees, -2);

  wall = Background::create("wall.png",8);
  addChild(wall,-1);

  ground = Background::create("ground.png",16);
  addChild(ground, 0);

  snow = Background::create("snow.png",32);
  addChild(snow, 1);

  cocos2d::Size visibleSize = cocos2d::
    Director::getInstance()->getVisibleSize();
  cocos2d::Vec2 origin = cocos2d::
    Director::getInstance()->getVisibleOrigin();

  /////////////////////////////
  // 2. add a menu item with "X" image, which is clicked to quit the program
  //    you may modify it.

  // add a "close" icon to exit the progress. it's an autorelease object
  cocos2d::MenuItemImage* closeItem = cocos2d::MenuItemImage::create(
    "CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(Remembrance::menuCloseCallback, this));
    
  closeItem->setPosition(cocos2d::Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2,
    origin.y + closeItem->getContentSize().height/2));

  // create menu, it's an autorelease object
  cocos2d::Menu* menu = cocos2d::Menu::create(closeItem, NULL);
  menu->setPosition(cocos2d::Vec2::ZERO);
  this->addChild(menu, 4);

  /////////////////////////////
  // 3. add your codes below...

  // add a label shows "Hello World"
  // create and initialize a label
    
  cocos2d::Label* label = cocos2d::Label::createWithTTF("Sarah Martin & Cassidy Lamm", "fonts/Marker Felt.ttf", 24);
    
  // position the label on the center of the screen
  label->setPosition(cocos2d::Vec2(origin.x + visibleSize.width/2,
    origin.y + visibleSize.height - label->getContentSize().height));

  // add the label as a child to this layer
  addChild(label, 2);

  boy = new Boy;
  myPixies.push_back(boy);
  explosion = new Exp(this,"monster.png",
	visibleSize.width+175,200, -100,200);

  generateGhosts();
  generateBullet();
  int count = 0;
  
  for(std::list<Pixie*>::iterator iter = myPixies.begin();
	 iter != myPixies.end(); ++iter){
    if(count == 0){
      addChild((*iter)->getSprite(),4);	
    }

    else{
      if(count%2 == 0){
	(*iter)->getSprite()->setScaleX(0.75);
	(*iter)->getSprite()->setScaleY(0.75);
        addChild((*iter)->getSprite(),-2);
      }
      else{
        addChild((*iter)->getSprite(),1);
      }
    }
    count++;
  } 

  scheduleUpdate();

  cocos2d::EventListenerTouchOneByOne *touchListen =
	 cocos2d::EventListenerTouchOneByOne::create();
  touchListen->onTouchBegan = CC_CALLBACK_2(Remembrance::onTouchBegan, this);
  touchListen->onTouchEnded = CC_CALLBACK_2(Remembrance::onTouchEnded,this);
  touchListen->onTouchMoved = CC_CALLBACK_2(Remembrance::onTouchMoved, this);
  touchListen->onTouchCancelled = CC_CALLBACK_2(Remembrance::onTouchCancelled,this);

  _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListen, this);


  CocosDenshion::SimpleAudioEngine::
		getInstance()->playEffect("audio/tomorrow.mp3");
  return true;
}


void Remembrance::menuCloseCallback(Ref* pSender)
{
    cocos2d::Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
