#include "PoweredBy.h"
#include "BlackScreenScene1.h"
#include "Definitions.h"

USING_NS_CC;

Scene* PoweredBy::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = PoweredBy::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PoweredBy::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->scheduleOnce(schedule_selector(PoweredBy::GoToBlackScreenScene1), DISPLAY_TIME_SPLASH_SCENE);

	{
		auto PoweredBy = MenuItemImage::create("Buttons/PoweredBy.png", "Buttons/PoweredBy.png");
		PoweredBy->setPosition(Point(visibleSize.width / 3 + origin.x - 85, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 0.1);
		float SizeY = visibleSize.height / (visibleSize.height * 0.1);
		PoweredBy->setScale(SizeX * SizeY * 0.0090);
		this->addChild(PoweredBy);
	}


	{
		//background image
		auto Cocos2D = Sprite::create("Cocos.png");
		Cocos2D->setPosition(Point(visibleSize.width / 2 + origin.x + 20, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 0.1);
		float SizeY = visibleSize.height / (visibleSize.height * 0.1);
		Cocos2D->setScale(SizeX * SizeY * 0.0075);
		this->addChild(Cocos2D);
	}
	

	
    return true;
}

void PoweredBy::GoToBlackScreenScene1(float dt)
{
	auto scene = BlackScreenScene1::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}



