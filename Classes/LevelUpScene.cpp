#include "LevelUpScene.h"
#include "BlackScreenScene2.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

namespace
{
	int Level;
}

Scene* LevelUpScene::createScene(int level)
{
	Level = level;
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = LevelUpScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void LevelUpScene::preloadSounds()
{
	auto sounds = CocosDenshion::SimpleAudioEngine::getInstance();
	sounds->preloadBackgroundMusic("sounds/LevelUp.mp3");
}

// on "init" you need to initialize your instance
bool LevelUpScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    

	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	preloadSounds();
	

	{
		auto MainMenuBackground = Sprite::create("MainMenuBackground.jpg");
		MainMenuBackground->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 1);
		float SizeY = visibleSize.height / (visibleSize.width * 1);
		MainMenuBackground->setScale(SizeX * SizeY);
		this->addChild(MainMenuBackground);
	}

	
	std::string level[10] = { "Buttons/Level1.png", "Buttons/Level2.png", "Buttons/Level3.png", "Buttons/Level4.png", "Buttons/Level5.png", "Buttons/Level6.png", "Buttons/Level7.png", "Buttons/Level8.png", "Buttons/Level9.png", "Buttons/Level10.png" };
	auto LevelUp = MenuItemImage::create(level[Level - 1], level[Level - 1]);
	LevelUp->setPosition(Point(visibleSize.width / 2 + origin.x - 40, visibleSize.height / 2 + origin.y));
	float SizeX = visibleSize.width / (visibleSize.width * 0.1);
	float SizeY = visibleSize.height / (visibleSize.height * 0.1);
	LevelUp->setScale(SizeX * SizeY * 0.0081);
	this->addChild(LevelUp);
		
		this->schedule(schedule_selector(LevelUpScene::GoToGameScene), LEVELUP_SCENE_TIME);
		this->scheduleOnce(schedule_selector(LevelUpScene::StartBackgroundMusic), 0.5f);

		
    return true;
}

void LevelUpScene::GoToGameScene(float delaytime)
{
	auto scene = BlackScreenScene2::createScene(Level);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	
}

void LevelUpScene::StartBackgroundMusic(float delaytime)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sounds/LevelUp.mp3");
}

