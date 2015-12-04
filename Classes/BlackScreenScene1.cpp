#include "BlackScreenScene1.h"
#include "Definitions.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* BlackScreenScene1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = BlackScreenScene1::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BlackScreenScene1::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init() )
    {
        return false;
    }
    
	this->scheduleOnce(schedule_selector(BlackScreenScene1::GoToMainMenuScene), DISPLAY_TIME_BLACKSCREEN_SCENE);
		
    return true;
}

void BlackScreenScene1::GoToMainMenuScene(float dt)
{
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(scene);

}



