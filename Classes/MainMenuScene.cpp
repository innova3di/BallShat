#include "MainMenuScene.h"
#include "LevelUpScene.h"
#include "Definitions.h"
#include "GuideScene.h"
#include "FileOperation.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

inline void MainMenuScene::preloadSounds()
{
	auto sounds = CocosDenshion::SimpleAudioEngine::getInstance();

	sounds->preloadBackgroundMusic("sounds/MoveForward.mp3");
	sounds->preloadEffect("sounds/click.mp3");
}


// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	
	preloadSounds();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sounds/MoveForward.mp3", true);

	//Background
	auto MainMenuBackground = Sprite::create("MainMenuBackground.jpg");
	MainMenuBackground->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	float SizeX = visibleSize.width / (visibleSize.width * 1);
	float SizeY = visibleSize.height / (visibleSize.width * 1);
	MainMenuBackground->setScale(SizeX * SizeY );
	this->addChild(MainMenuBackground, -1);

	{
		auto Title = MenuItemImage::create("Buttons/BallShat.png", "Buttons/BallShat.png");
		Title->setPosition(Point(visibleSize.width / 3 + origin.x - 80, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 0.1);
		float SizeY = visibleSize.height / (visibleSize.height * 0.1);
		Title->setScale(SizeX * SizeY * 0.0080);
		this->addChild(Title);
	}

	//reads the XML file for saved game
	int level = FileOperation::readFile();
	
	if (level > 1)
	{
		//Game menu
		auto resumeItem = MenuItemImage::create("Buttons/Resume.png", "Buttons/ResumeClicked.png", CC_CALLBACK_1(MainMenuScene::ResumeToGameScene, this));
		auto NewGame = MenuItemImage::create("Buttons/NewGame.png", "Buttons/NewGameClicked.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
		auto GuideItem = MenuItemImage::create("Buttons/Guide.png", "Buttons/GuideClicked.png", CC_CALLBACK_1(MainMenuScene::GoToGuideScene, this));
		auto Quit = MenuItemImage::create("Buttons/Quit.png", "Buttons/QuitClicked.png", CC_CALLBACK_1(MainMenuScene::Quit, this));

		{
			resumeItem->setPosition(Point(visibleSize.width / 2 + origin.x - 80, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			resumeItem->setScale(SizeX * SizeY * 0.0080);
		}
		{
			NewGame->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			NewGame->setScale(SizeX * SizeY * 0.0081);

		}
		{
			GuideItem->setPosition(Point(visibleSize.width / 2 + origin.x + 85, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			GuideItem->setScale(SizeX * SizeY * 0.0070);
		}
		{
			Quit->setPosition(Point(visibleSize.width / 2 + origin.x + 165, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			Quit->setScale(SizeX * SizeY * 0.0080);

		}

		auto menu = Menu::create(resumeItem, NewGame, GuideItem, Quit, NULL);
		menu->setPosition(Point::ZERO);
		this->addChild(menu);
	}

	else
	{
		//Game menu
		auto playItem = MenuItemImage::create("Buttons/Play.png", "Buttons/PlayClicked.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
		auto GuideItem = MenuItemImage::create("Buttons/Guide.png", "Buttons/GuideClicked.png", CC_CALLBACK_1(MainMenuScene::GoToGuideScene, this));
		auto Quit = MenuItemImage::create("Buttons/Quit.png", "Buttons/QuitClicked.png", CC_CALLBACK_1(MainMenuScene::Quit, this));

		{
			playItem->setPosition(Point(visibleSize.width / 2 + origin.x - 50, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			playItem->setScale(SizeX * SizeY * 0.0080);
		}
		{
			GuideItem->setPosition(Point(visibleSize.width / 2 + origin.x + 50, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			GuideItem->setScale(SizeX * SizeY * 0.0070);
		}
		{
			Quit->setPosition(Point(visibleSize.width / 2 + origin.x + 150, visibleSize.height / 2 + origin.y));
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			Quit->setScale(SizeX * SizeY * 0.0080);
		}

		auto menu = Menu::create(playItem, GuideItem, Quit, NULL);
		menu->setPosition(Point::ZERO);
		this->addChild(menu);
	}

    return true;
}

void MainMenuScene::ResumeToGameScene(cocos2d::Ref *sender)
{
	int level = FileOperation::readFile();
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/click.mp3");
	auto scene = LevelUpScene::createScene(level);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}

void MainMenuScene::GoToGameScene(cocos2d::Ref *sender)
{
	int level = FileOperation::readFile();
	if (level != 1)
	{
		//for Game Progress auto saving
		{
			
			#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
			__Dictionary* dictionary = Dictionary::createWithContentsOfFile("/data/data/leandro.gecozo.ballshat/GameData.xml");
			#endif
			#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
			__Dictionary* dictionary = Dictionary::createWithContentsOfFile("E:/GameData.xml");
			#endif
			FileOperation::saveFile("1");
		}

	}
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/click.mp3");
		auto scene = LevelUpScene::createScene(1);
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	
}
void MainMenuScene::GoToGuideScene(cocos2d::Ref *sender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/click.mp3");
	auto scene = GuideScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void MainMenuScene::Quit(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/click.mp3");
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}