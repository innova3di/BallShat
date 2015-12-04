#include "SplashScene.h"
#include "Definitions.h"
#include "PoweredBy.h"


USING_NS_CC;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->scheduleOnce(schedule_selector(SplashScene::GoToPoweredByScene), DISPLAY_TIME_SPLASH_SCENE);
    

	//background image
	auto SplashScreen = Sprite::create("SplashScreen.jpg");
	SplashScreen->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	float SizeX = visibleSize.width / (visibleSize.width * 1);
	float SizeY = visibleSize.height / (visibleSize.width * 1);

	SplashScreen->setScale(SizeX * SizeY * 1.5);

	this->addChild(SplashScreen);

    return true;
}

void SplashScene::GoToPoweredByScene(float dt)
{
	auto scene = PoweredBy::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}