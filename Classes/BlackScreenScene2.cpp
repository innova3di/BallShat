#include "BlackScreenScene2.h"
#include "Definitions.h"
#include "GameSceneGenerator.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;
namespace
{
	int Level;
}
Scene* BlackScreenScene2::createScene(int level)
{
	Level = level;
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = BlackScreenScene2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BlackScreenScene2::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init() )
    {
        return false;
    }
    
	this->scheduleOnce(schedule_selector(BlackScreenScene2::GoToGameScene), DISPLAY_TIME_BLACKSCREEN_SCENE);
		
    return true;
}

void BlackScreenScene2::GoToGameScene(float dt)
{
	auto scene = GameSceneGenerator::createScene(Level);

	Director::getInstance()->replaceScene(scene);
	
}



