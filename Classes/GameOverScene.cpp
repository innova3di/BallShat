#include "GameOverScene.h"
#include "BlackScreenScene2.h"
#include "SplashScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

namespace
{
	int Level;
	std::string Message;
	
}

Scene* GameOverScene::createScene(int level, std::string message)
{
	Level = level;
	Message = message;
	

    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void GameOverScene::preloadSounds()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sounds/click.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sounds/oops.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sounds/intertwined.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sounds/QuirkyDog.mp3");
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	{
		auto MainMenuBackground = Sprite::create("MainMenuBackground.jpg");
		MainMenuBackground->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 1);
		float SizeY = visibleSize.height / (visibleSize.width * 1);
		MainMenuBackground->setScale(SizeX * SizeY);
		this->addChild(MainMenuBackground);
	}


	

	if (Message == "Your Ball Got Sucked")
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sounds/intertwined.mp3", true);

		auto Sucked = MenuItemImage::create("Buttons/Sucked.png", "Buttons/Sucked.png");
		Sucked->setPosition(Point(visibleSize.width / 3 + origin.x - 50, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 0.1);
		float SizeY = visibleSize.height / (visibleSize.height * 0.1);
		Sucked->setScale(SizeX * SizeY * 0.0090);
		this->addChild(Sucked);

		//Game menu and Main Menu
		auto RetryItem = MenuItemImage::create("Buttons/Retry.png", "Buttons/RetryClicked.png", CC_CALLBACK_1(GameOverScene::GoToGameScene, this));
		auto MainMenuItem = MenuItemImage::create("Buttons/MainMenu.png", "Buttons/MainMenuClicked.png", CC_CALLBACK_1(GameOverScene::GoToMainMenuScene, this));

		{
			RetryItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			RetryItem->setScale(SizeX * SizeY * 0.0080);

		}
		
		{
			MainMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			MainMenuItem->setScale(SizeX * SizeY * 0.0080);

		}
	
		auto menu = Menu::create(RetryItem, MainMenuItem, NULL);
		menu->setPosition(Point::ZERO);
		this->addChild(menu);

		this->scheduleOnce(schedule_selector(GameOverScene::PlayErrorSoundEffect), 0.6f);
	}
	else if (Message == "Out of Balls")
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sounds/intertwined.mp3", true);

		auto OutofBalls = MenuItemImage::create("Buttons/OutofBalls.png", "Buttons/OutofBalls.png");
		OutofBalls->setPosition(Point(visibleSize.width / 3 + origin.x - 50, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 0.1);
		float SizeY = visibleSize.height / (visibleSize.height * 0.1);
		OutofBalls->setScale(SizeX * SizeY * 0.0080);

		this->addChild(OutofBalls);

		//Game menu and Main Menu
		auto RetryItem = MenuItemImage::create("Buttons/Retry.png", "Buttons/RetryClicked.png", CC_CALLBACK_1(GameOverScene::GoToGameScene, this));
		auto MainMenuItem = MenuItemImage::create("Buttons/MainMenu.png", "Buttons/MainMenuClicked.png", CC_CALLBACK_1(GameOverScene::GoToMainMenuScene, this));
		
		{
			RetryItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			RetryItem->setScale(SizeX * SizeY * 0.0080);
		}
		{
			MainMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			MainMenuItem->setScale(SizeX * SizeY * 0.0080);
		}
	


		auto menu = Menu::create(RetryItem, MainMenuItem, NULL);
		menu->setPosition(Point::ZERO);
		this->addChild(menu);

		this->scheduleOnce(schedule_selector(GameOverScene::PlayErrorSoundEffect), 0.7f);

		
		
	}
	else if (Message == "All Levels Cleared")
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sounds/QuirkyDog.mp3", true);
		
			auto Cleared = MenuItemImage::create("Buttons/AllCleared.png", "Buttons/AllCleared.png");
			Cleared->setPosition(Point(visibleSize.width / 3 + origin.x + 25, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			Cleared->setScale(SizeX * SizeY * 0.0080);
			this->addChild(Cleared);

		{
			auto MainMenuItem = MenuItemImage::create("Buttons/MainMenu.png", "Buttons/MainMenuClicked.png", CC_CALLBACK_1(GameOverScene::GoToMainMenuScene, this));
			MainMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x + 170, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			MainMenuItem->setScale(SizeX * SizeY * 0.0080);

			auto menu = Menu::create(MainMenuItem, NULL);
			menu->setPosition(Point::ZERO);
			this->addChild(menu);
		}


		
	}



    return true;
}

void GameOverScene::GoToGameScene(cocos2d::Ref *sender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/click.mp3");
	auto scene = BlackScreenScene2::createScene(Level);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


void GameOverScene::GoToMainMenuScene(cocos2d::Ref *sender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/click.mp3");
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameOverScene::PlayErrorSoundEffect(float delaytime)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/oops.mp3");
}