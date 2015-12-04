#include "BlackScreenScene.h"
#include "SplashScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* BlackScreenScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = BlackScreenScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BlackScreenScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
 

	this->scheduleOnce(schedule_selector(BlackScreenScene::GoToSplashScreen), DISPLAY_TIME_BLACKSCREEN_SCENE);
		
    return true;
}

void BlackScreenScene::GoToSplashScreen(float dt)
{
	auto scene = SplashScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}



