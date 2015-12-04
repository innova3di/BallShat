#include "MainMenuScene.h"
#include "Definitions.h"
#include "GuideScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GuideScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = GuideScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GuideScene::init()
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
		//Background
		auto MainMenuBackground = Sprite::create("MainMenuBackground.jpg");
		MainMenuBackground->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 1);
		float SizeY = visibleSize.height / (visibleSize.width * 1);
		MainMenuBackground->setScale(SizeX * SizeY);
		this->addChild(MainMenuBackground, -1);
	}
	


	{
		auto HowToPlay = MenuItemImage::create("Buttons/HowToPlay.png", "Buttons/HowToPlay.png");
		HowToPlay->setPosition(Point(visibleSize.width / 2 + origin.x - 30, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 0.1);
		float SizeY = visibleSize.height / (visibleSize.height * 0.1);
		HowToPlay->setScale(SizeX * SizeY * 0.011);
		this->addChild(HowToPlay);
	}



    //Game menu

	auto MainMenuItem = MenuItemImage::create("Buttons/MainMenu.png", "Buttons/MainMenuClicked.png", CC_CALLBACK_1(GuideScene::GoToMainMenuScene, this));
	MainMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x + 180, visibleSize.height / 2 + origin.y));
	float SizeX = visibleSize.width / (visibleSize.width * 0.1);
	float SizeY = visibleSize.height / (visibleSize.height * 0.1);
	MainMenuItem->setScale(SizeX * SizeY * 0.0080);

	auto menu = Menu::create(MainMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	

    return true;
}





void GuideScene::GoToMainMenuScene(cocos2d::Ref *sender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sounds/click.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/click.mp3");
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}