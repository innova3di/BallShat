#pragma once

#include "cocos2d.h"
#include "GameSceneGenerator.h"

class Marble : protected GameSceneGenerator
{
public:
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	

	cocos2d::Sprite* spawnMarble(int i, int positionX, int positionY, std::string file);
	cocos2d::Sprite* spawnPlayersBall(int i);
	cocos2d::Sprite* spawnCharges(int i, int level);


private:
	
	

}; 