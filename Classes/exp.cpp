#include <iostream>
#include <cmath>
#include <cstdlib>
#include <list>
#include "exp.h"

Exp::~Exp(){
	std::list<Pixie*>::iterator ptr = showlist.begin();
	while( ptr != showlist.end()){
		delete *ptr;
		ptr++;
	}
	ptr = freelist.begin();
	while( ptr != freelist.end()){
		delete *ptr;
		ptr++;
	}
}

Exp::Exp(cocos2d::Layer* p, const std::string name, const float lx, const float ly) : 
	Enemy(p, name, lx, ly),
	showlist(),
	freelist(),
	count(0),
	explode(false),
    layer(p)
{ 
}

Exp::Exp(cocos2d::Layer* p, const std::string name, const float lx, const float ly,
  const float vx, const float vy) : 
	Enemy(p, name, lx, ly, vx, vy),
	showlist(),
	freelist(),
	count(0),
	explode(false),
    layer(p),
	xVel(-100)
{ 
}

void Exp::update(float dt) {

		Enemy::update(dt);
		if(explode)
		{
			makechunks();	
			explode = false;
			xVel = xVel - 50;
			Enemy::setVelocity(
							cocos2d::Vec2(0,0));
		}
		else
		{			
			std::list<Pixie*>::iterator ptr = showlist.begin();
			std::list<Pixie*>::iterator end = showlist.end();
			--end;
			while(ptr!=showlist.end()){
				(*ptr)->update(dt);
				if(this->getDistance(*ptr) > 10000){
					(*ptr)->getSprite()->setVisible(false);
					freelist.push_back((*ptr));
					ptr = showlist.erase(ptr);
					if(ptr == end){
						count = 0;
						explode = false;		
						
						getSprite()->setPosition(
							Enemy::getViewSize().width+175, 
							rand() % 400);
						
						Enemy::setVelocity(
							cocos2d::Vec2(xVel,200));
						getSprite()->setVisible(true);
					
					}
				}else	++ptr;
			}
		}
}


float Exp::getDistance( const Pixie* p ) const {
	return Enemy::getDistance(p);
}

void Exp::makechunks(){
	getSprite()->setVisible(false);

	// When new a chunk, constructor will call addChild.
	// Otherwise, we will addChild at here.
	if(freelist.size()>0){		
		std::list<Pixie*>::iterator ptr = freelist.begin();
		while(ptr!=freelist.end()){
			(*ptr)->getSprite()->setVisible(true);
			showlist.push_back(*ptr);
			ptr=freelist.erase(ptr);
		}
	}
	else{
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				showlist.push_back(new Chunk( layer, "monster.png", getPos().x, getPos().y, 100, 100, i*45, j*24, 45, 24));
			}
		}
	}
	resetshowlist();
}

// Reset position and velocity.
// Compute velocity range [150, 250] in random angle.
void Exp::resetshowlist(){
	float px = getPos().x;
	float py = getPos().y;

	std::list<Pixie*>::iterator ptr = showlist.begin();
	int i=0,j=0; 

	while (ptr != showlist.end()){
		int x = px-15*(4-2*i-1)/8 - (rand() % 100);
		int y = py+8*(4-2*j-1)/8 +(rand() % 100);
		(*ptr)->getSprite()->setPosition(cocos2d::Vec2(x,y));
		i=(i+1)%4;
		if(i==0) j++;
		++ptr;
	}
}
