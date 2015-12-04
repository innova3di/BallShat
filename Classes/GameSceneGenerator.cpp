#include "GameSceneGenerator.h"
#include "SimpleAudioEngine.h"
#include <assert.h>
#include <cassert>
#include "MyBodyParser.h"
#include "GameOverScene.h"
#include "Definitions.h"
#include "Marble.h"
#include "LevelUpScene.h"
#include "Definitions.h"
#include "FileOperation.h"


namespace
{
	//Global Variable that is responsible for transitioning Levels to different scenes
	//This Global Variable is required
	int Level;
}

//Create number shots for the player to execute
void GameSceneGenerator::createCharges(float delaytime)
{
	static int Index = 0;
		Marble PlayerBallCharges;
		{
			auto childNode = PlayerBallCharges.spawnCharges(Index, Level);
			Charges[Index] = Marbles(childNode);

			this->addChild(Charges[Index], -1);
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/pong.wav");
		}
		Index++;
		
	if (Level == 4)
	{
		BallCounter = 11;
		index = 10;
		if (Index == 11)
		{
			Index = 0;
			this->unschedule(schedule_selector(GameSceneGenerator::createCharges));
			SpawnChargesDone = true;
		}
	}
	else if (Level == 5)
	{
		BallCounter = 13;
		index = 12;
		if (Index == 13)
		{
			Index = 0;
			this->unschedule(schedule_selector(GameSceneGenerator::createCharges));
			SpawnChargesDone = true;
		}
	}
	else if (Level == 6)
	{
		BallCounter = 17;
		index = 16;
		if (Index == 17)
		{
			Index = 0;
			this->unschedule(schedule_selector(GameSceneGenerator::createCharges));
			SpawnChargesDone = true;
		}
	}
	else if (Level == 7)
	{
		BallCounter = 17;
		index = 16;
		if (Index == 17)
		{
			Index = 0;
			this->unschedule(schedule_selector(GameSceneGenerator::createCharges));
			SpawnChargesDone = true;
		}
	}
	else if (Level == 8)
	{
		BallCounter = 20;
		index = 19;
		if (Index == 20)
		{
			Index = 0;
			this->unschedule(schedule_selector(GameSceneGenerator::createCharges));
			SpawnChargesDone = true;
		}
	}
	else if (Level == 9)
	{
		BallCounter = 23;
		index = 22;
		if (Index == 23)
		{
			Index = 0;
			this->unschedule(schedule_selector(GameSceneGenerator::createCharges));
			SpawnChargesDone = true;
		}
	}
	else if (Level == 10)
	{
		BallCounter = 26;
		index = 25;
		if (Index == 26)
		{
			Index = 0;
			this->unschedule(schedule_selector(GameSceneGenerator::createCharges));
			SpawnChargesDone = true;
		}
	}
	else
	{
		BallCounter = 10;
		index = 9;
		if (Index == 10)
		{
			Index = 0;
			this->unschedule(schedule_selector(GameSceneGenerator::createCharges));
			SpawnChargesDone = true;
		}
	}

}
//PlayersBall
void GameSceneGenerator::createPlayersBall()
{
	Marble PlayersMarble;
	{
		auto childNode = PlayersMarble.spawnPlayersBall(0);
		Ball[0] = Marbles(childNode);
		this->addChild(Ball[0]);
	}
}
//Marbles that is meant to be shot by Player
void GameSceneGenerator::createMarbleWithtDelay(float delaytime)
{
	static int index = 1;
	std::string MarbleFile[10] = { "Marbles/Marble1.png", "Marbles/Marble2.png", "Marbles/Marble3.png", "Marbles/Marble4.png",
		"Marbles/Marble5.png", "Marbles/Marble6.png",  "Marbles/Marble7.png",  "Marbles/Marble8.png",  "Marbles/Marble9.png", 
		"Marbles/Marble10.png" };

		static int X[12] = { +55, +20, +20, -16, -16, -16, -52, -52, -88 };
		static int Y[12] = {   0, +21, -21,   0, +42, -42, +21, -21, 0 };
		
		Marble marble;
		{
			int negator = 1;
		
			auto childNode = marble.spawnMarble(index, X[index - negator], Y[index - negator], MarbleFile[Level - 1]);

			Ball[index] = Marbles(childNode);

			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/BallHit2.wav");

			this->addChild(Ball[index]);
		}

		index++;

	int NumberOfMarbles[10] = {4, 5, 6, 7, 8, 8, 9, 9, 10, 10};
	
	if (index == NumberOfMarbles[Level - 1])
			{
				index = 1;
				this->unschedule(schedule_selector(GameSceneGenerator::createMarbleWithtDelay));

				//Method scheduler for creation of charges that is supplied in different level for the player to execute
				this->schedule(schedule_selector(GameSceneGenerator::createCharges), MARBLECHARGES_SPAWN_FREQUENCY);
			}
}

void GameSceneGenerator::createRocks(int level)
{
		if (level == 6)
		{
			for (int i = 0; i < 2;)
			{
				int positionX[2] = { +60, -120 };
				int positionY[2] = { 75, -70 };

				Sprite* Rock = Sprite::create("Rocks/Rock1.png");
				Rock->setPosition(Point(visibleSize.width / 2 + origin.x + positionX[i], visibleSize.height / 2 + origin.y - positionY[i]));
				float SizeX = visibleSize.width / (visibleSize.width * 0.1);
				float SizeY = visibleSize.height / (visibleSize.height * 0.1);
				Rock->setScale(SizeX * SizeY * 0.009);
				cocos2d::Size ContentSize = visibleSize * 0.07f;
				Rock->setContentSize(ContentSize);
				MyBodyParser::getInstance()->parseJsonFile("Rocks/Rock1.json");
				auto spriteBody = MyBodyParser::getInstance()->bodyFormJson(Rock, "Rock1", PhysicsMaterial(0, 0.5, 0));
				spriteBody->setCollisionBitmask(3);
				spriteBody->setContactTestBitmask(true);
				if (spriteBody != nullptr)
				{
					spriteBody->setDynamic(false);
					Rock->setPhysicsBody(spriteBody);
				}
				this->addChild(Rock);
				i++;
			}
		}
		if (level == 7)
		{
			for (int i = 0; i < 2;)
			{
				std::string RockFile[2] = { "Rocks/Rock2.png", "Rocks/Rock3.png" };
				std::string RockJson[2] = { "Rocks/Rock2.json", "Rocks/Rock3.json" };
				std::string RockName[2] = { "Rock2", "Rock3" };
				int positionX[2] = { -100, -100 };
				int positionY[2] = { 75, -65 };

				Sprite* Rock = Sprite::create(RockFile[i]);
				Rock->setPosition(Point(visibleSize.width / 2 + origin.x + positionX[i], visibleSize.height / 2 + origin.y - positionY[i]));
				float SizeX = visibleSize.width / (visibleSize.width * 0.1);
				float SizeY = visibleSize.height / (visibleSize.height * 0.1);

				if (RockFile[i] == "Rocks/Rock3.png")
				{
					Rock->setScale(SizeX * SizeY * 0.009);
					cocos2d::Size ContentSize = visibleSize * 0.065f;
					Rock->setContentSize(ContentSize);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody->setCollisionBitmask(3);
					spriteBody->setContactTestBitmask(true);
					if (spriteBody != nullptr)
					{
						spriteBody->setDynamic(false);
						Rock->setPhysicsBody(spriteBody);
					}
					this->addChild(Rock);
					i++;
				}
				else
				{
					Rock->setScale(SizeX * SizeY * 0.01);
					cocos2d::Size ContentSize = visibleSize * 0.08f;
					Rock->setContentSize(ContentSize);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody->setCollisionBitmask(3);
					spriteBody->setContactTestBitmask(true);
					if (spriteBody != nullptr)
					{
						spriteBody->setDynamic(false);
						Rock->setPhysicsBody(spriteBody);
					}
					this->addChild(Rock);
					i++;
				}
			}
		}

		if (level == 8)
		{
			for (int i = 0; i < 3;)
			{
				std::string RockFile[3] = { "Rocks/Rock4.png", "Rocks/Rock5.png", "Rocks/Rock6.png", };
				std::string RockJson[3] = { "Rocks/Rock4.json", "Rocks/Rock5.json", "Rocks/Rock6.json", };
				std::string RockName[3] = { "Rock4", "Rock5", "Rock6", };
				int positionX[3] = {-100, -100, 100};
				int positionY[3] = { 75, -70, -70 };

				Sprite* Rock = Sprite::create(RockFile[i]);
				Rock->setPosition(Point(visibleSize.width / 2 + origin.x + positionX[i], visibleSize.height / 2 + origin.y + positionY[i]));
				float SizeX = visibleSize.width / (visibleSize.width * 0.1);
				float SizeY = visibleSize.height / (visibleSize.height * 0.1);

				if (RockFile[i] == "Rocks/Rock4.png")
				{
					cocos2d::Size ContentSize = visibleSize * 0.090f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.0090);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}
				else if (RockFile[i] == "Rocks/Rock5.png")
				{
					cocos2d::Size ContentSize = visibleSize * 0.08f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.011);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}
				else
				{
					cocos2d::Size ContentSize = visibleSize * 0.09f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.011);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}
			}
		}
		if (level == 9)
		{
			for (int i = 0; i < 4;)
			{
				std::string RockFile[4] = { "Rocks/Rock7.png", "Rocks/Rock8.png", "Rocks/Rock9.png", "Rocks/Rock10.png" };
				std::string RockJson[4] = { "Rocks/Rock7.json", "Rocks/Rock8.json", "Rocks/Rock9.json", "Rocks/Rock10.json" };
				std::string RockName[4] = { "Rock7", "Rock8", "Rock9", "Rock10" };
				int positionX[4] = { -100, -100, 100, 100 };
				int positionY[4] = { 60, -70, -70, 65 };

				if (RockFile[i] == "Rocks/Rock8.png")
				{
					Sprite* Rock = Sprite::create(RockFile[i]);
					Rock->setPosition(Point(visibleSize.width / 2 + origin.x + positionX[i], visibleSize.height / 2 + origin.y + positionY[i]));
					float SizeX = visibleSize.width / (visibleSize.width * 0.1);
					float SizeY = visibleSize.height / (visibleSize.height * 0.1);
					cocos2d::Size ContentSize = visibleSize * 0.08f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.011);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}
				else
				{
					Sprite* Rock = Sprite::create(RockFile[i]);
					Rock->setPosition(Point(visibleSize.width / 2 + origin.x + positionX[i], visibleSize.height / 2 + origin.y + positionY[i]));
					float SizeX = visibleSize.width / (visibleSize.width * 0.1);
					float SizeY = visibleSize.height / (visibleSize.height * 0.1);
					cocos2d::Size ContentSize = visibleSize * 0.065f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.0085);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}
			}
		}
		if (level == 10)
		{
			std::string RockFile[6] = { "Rocks/Rock1.png", "Rocks/Rock4.png", "Rocks/Rock11.png", "Rocks/Rock12.png" };
			std::string RockJson[6] = { "Rocks/Rock1.json", "Rocks/Rock4.json", "Rocks/Rock11.json", "Rocks/Rock12.json" };
			std::string RockName[6] = { "Rock1", "Rock4", "Rock11", "Rock12" };
			int positionX[6] = { -100, -100, 100, 100, -220 };
			int positionY[6] = { 65, -70, -75, 65, 20 };
			for (int i = 0; i < 4;)
			{
				Sprite* Rock = Sprite::create(RockFile[i]);
				Rock->setPosition(Point(visibleSize.width / 2 + origin.x + positionX[i], visibleSize.height / 2 + origin.y + positionY[i]));
				float SizeX = visibleSize.width / (visibleSize.width * 0.1);
				float SizeY = visibleSize.height / (visibleSize.height * 0.1);

				if (RockFile[i] == "Rocks/Rock11.png")
				{
					cocos2d::Size ContentSize = visibleSize * 0.070f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.01);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}
				else if (RockFile[i] == "Rocks/Rock4.png")
				{
					cocos2d::Size ContentSize = visibleSize * 0.095f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.0095);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}
				else if (RockFile[i] == "Rocks/Rock12.png")
				{
					cocos2d::Size ContentSize = visibleSize * 0.065f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.0095);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}
				else
				{
					cocos2d::Size ContentSize = visibleSize * 0.075f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.0095);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}

			}
			{
				std::string RockFile[2] = { "Rocks/Rock13.png", "Rocks/Rock14.png" };
				std::string RockJson[2] = { "Rocks/Rock13.json", "Rocks/Rock14.json" };
				std::string RockName[2] = { "Rock13", "Rock14" };
				int positionX[2] = { -220, -220 };
				int positionY[2] = { 20, -30 };
				for (int i = 0; i < 2;)
				{
					Sprite* Rock = Sprite::create(RockFile[i]);
					Rock->setPosition(Point(visibleSize.width / 2 + origin.x + positionX[i], visibleSize.height / 2 + origin.y + positionY[i]));
					float SizeX = visibleSize.width / (visibleSize.width * 0.1);
					float SizeY = visibleSize.height / (visibleSize.height * 0.1);
					cocos2d::Size ContentSize = visibleSize * 0.075f;
					Rock->setContentSize(ContentSize);
					Rock->setScale(SizeX * SizeY * 0.0095);
					MyBodyParser::getInstance()->parseJsonFile(RockJson[i]);
					auto spriteBody4 = MyBodyParser::getInstance()->bodyFormJson(Rock, RockName[i], PhysicsMaterial(0, 0.5, 0));
					spriteBody4->setCollisionBitmask(3);
					spriteBody4->setContactTestBitmask(true);
					if (spriteBody4 != nullptr)
					{
						spriteBody4->setDynamic(false);
						Rock->setPhysicsBody(spriteBody4);
					}
					this->addChild(Rock);
					i++;
				}

			}
		
		}
}
//Create Scene
Scene* GameSceneGenerator::createScene(int level)
{
	Level = level;

	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

	// 'layer' is an autorelease object
	auto layer = GameSceneGenerator::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
//Preload sounds for faster response time
void GameSceneGenerator::preloadSounds()
{
	auto sounds = CocosDenshion::SimpleAudioEngine::getInstance();

	sounds->preloadEffect("sounds/Hole.mp3");
	sounds->preloadEffect("sounds/BallHit2.wav");
	sounds->preloadEffect("sounds/LaunchBall6.mp3");
	sounds->preloadEffect("sounds/tock.mp3");
	sounds->preloadEffect("sounds/pong.wav");
	sounds->preloadBackgroundMusic("sounds/curious.mp3");
	sounds->preloadBackgroundMusic("sounds/DreamyGameMenu.mp3");
	sounds->preloadBackgroundMusic("sounds/UnwrittenReturn.mp3");
	sounds->preloadBackgroundMusic("sounds/8bitDungeonBoss.mp3");
	sounds->preloadBackgroundMusic("sounds/Spellbound.mp3");
	sounds->preloadBackgroundMusic("sounds/SecretsoftheSchoolyard.mp3");
	sounds->preloadBackgroundMusic("sounds/FutureGrid.mp3");
	sounds->preloadBackgroundMusic("sounds/IceFlow.mp3");
	sounds->preloadBackgroundMusic("sounds/DangerStorm.mp3");
	sounds->preloadBackgroundMusic("sounds/CyberDreams.mp3");
	
}
void GameSceneGenerator::playBGM(float delaytime)
{
	
	const char* BGMForEachLevels[10] = {"sounds/curious.mp3", "sounds/DreamyGameMenu.mp3", "sounds/UnwrittenReturn.mp3",
	"sounds/8bitDungeonBoss.mp3", "sounds/Spellbound.mp3", "sounds/SecretsoftheSchoolyard.mp3", "sounds/FutureGrid.mp3", "sounds/IceFlow.mp3",
	"sounds/DangerStorm.mp3", "sounds/CyberDreams.mp3"};
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(BGMForEachLevels[Level - 1], true);

}

// on "init" you need to initialize your instance
bool GameSceneGenerator::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	
	//pre load the sounds for faster sound response rate
	preloadSounds();
	this->scheduleOnce(schedule_selector(GameSceneGenerator::playBGM), 0.5f);
	

	//Physics EdgeBox Body for screen physics boundary
	{
		auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
		edgeBody->setCollisionBitmask(13);
		edgeBody->setContactTestBitmask(true);
		auto edgeNode = Node::create();
		edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		edgeNode->setPhysicsBody(edgeBody);
		this->addChild(edgeNode);
	}
	
	//for hole
	{
		std::string GroundHole[10] = { "Grounds/Level1Hole.png", "Grounds/ActualHole.png", "Grounds/Level3Hole.png", "Grounds/ActualHole.png"
			, "Grounds/ActualHole.png", "Grounds/ActualHole.png", "Grounds/Level7Hole.png", "Grounds/Level8Hole.png", "Grounds/Level9Hole.png",
			"Grounds/Level10Hole.png" };

		Sprite* ActualHole;
		ActualHole = Sprite::create(GroundHole[Level - 1]);
		ActualHole->setPosition(Point(visibleSize.width / 6 + origin.x - 40, visibleSize.height / 2 + origin.y));

		if (Level == 1 || Level == 3 || Level == 7 || Level == 8 || Level == 9 || Level == 10)
		{
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			ActualHole->setScale((SizeX * SizeY) * 0.01);
		}
		else
		{
			float SizeX = visibleSize.width / (visibleSize.width * 0.1);
			float SizeY = visibleSize.height / (visibleSize.height * 0.1);
			ActualHole->setScale((SizeX * SizeY) * 0.011);
		}

		this->addChild(ActualHole);

		//for Hole Body
		Sprite* Hole;
		Hole = Sprite::create("Grounds/Hole.png");
		Hole->setPosition(Point(visibleSize.width / 6 + origin.x - 40, visibleSize.height / 2 + origin.y - 1));
		cocos2d::Size ContentSize = visibleSize * 0.005f;
		Hole->setContentSize(ContentSize);
		MyBodyParser::getInstance()->parseJsonFile("Grounds/Hole.json");
		auto spriteBody = MyBodyParser::getInstance()->bodyFormJson(Hole, "Hole", PhysicsMaterial(0, 1, 0));
		spriteBody->setCollisionBitmask(12);
		spriteBody->setContactTestBitmask(true);

		if (spriteBody != nullptr)
		{

			spriteBody->setDynamic(false);
			Hole->setPhysicsBody(spriteBody);
		}
		this->addChild(Hole);
	}


	//for Ground Platform where marbles are placed
	{
		std::string Background[10] = { "Grounds/Ground1.jpg", "Grounds/Ground2.jpg", "Grounds/Ground3.jpg", "Grounds/Ground4.jpg",
			"Grounds/Ground5.jpg", "Grounds/Ground6.jpg", "Grounds/Ground7.jpg", "Grounds/Ground8.jpg","Grounds/Ground9.jpg", 
			"Grounds/Ground10.jpg" };

		auto spriteBackground = Sprite::create(Background[Level - 1]);
		spriteBackground->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		spriteBackground->setScaleX((visibleSize.width / spriteBackground->getContentSize().width) * 1);
		spriteBackground->setScaleY((visibleSize.height / spriteBackground->getContentSize().height) * 1);
		this->addChild(spriteBackground, -2);
	}

	//For Velocity Level border
	{
		Sprite* BorderIndicator = Sprite::create("Parameters/ParameterBorder.png");
		BorderIndicator->setPosition(Point(visibleSize.width / 1 + origin.x - 100, visibleSize.height / 1 + origin.y - 16));
		float SizeX = visibleSize.width / (visibleSize.width * 0.1);
		float SizeY = visibleSize.height / (visibleSize.height * 0.1);
		BorderIndicator->setScale(SizeX * SizeY * 0.0115);
		this->addChild(BorderIndicator);
	}

	//For Velocity parameter
	{
		Slider* slider = Slider::create();
		slider->loadBarTexture("Parameters/VelocityParameter.png");
		slider->loadSlidBallTextures("Parameters/Charges.png");
		slider->loadProgressBarTexture("Parameters/ParameterFIller.png");
		slider->setScale9Enabled(false);
		slider->setFlippedX(true);
		slider->setPercent(90);
		int percent = slider->getPercent();
		SetIncreasedVelocity(percent * 4);
		slider->setPosition(Point(visibleSize.width / 1 + origin.x - 100, visibleSize.height / 1 + origin.y - 16));
		float SizeX = visibleSize.width / (visibleSize.width * 0.1);
		float SizeY = visibleSize.height / (visibleSize.height * 0.1);
		slider->setScale(SizeX * SizeY * 0.0115);
		slider->addEventListener(CC_CALLBACK_2(GameSceneGenerator::sliderEvent, this));
		this->addChild(slider);
	}

	//Method callback schedule for marble cleared detection when all marbles are sucked into the hole
	this->schedule(schedule_selector(GameSceneGenerator::isMarblesCleared), 0.001f);

	//Collision Detection method callbacks
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameSceneGenerator::OnContactbegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	//create and position the player's marble
	createPlayersBall();

	//Method scheduler for marbles that is meant to be shot by the player
	this->schedule(schedule_selector(GameSceneGenerator::createMarbleWithtDelay), MARBLE_SPAWN_FREQUENCY);

	createRocks(Level);

	//touch event listeners
	auto listener = EventListenerTouchAllAtOnce::create();
	this->schedule(schedule_selector(GameSceneGenerator::TouchCallbacks), 0.000000001f);
	listener->onTouchesMoved = CC_CALLBACK_2(GameSceneGenerator::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GameSceneGenerator::onTouchesEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
	return true;
}

//this method becomes available when the spawncharges method is done
void GameSceneGenerator::TouchCallbacks(float delaytime)
{
	if (SpawnChargesDone == true)
	{
		
		{
			auto listener = EventListenerTouchAllAtOnce::create();
			listener->onTouchesBegan = CC_CALLBACK_2(GameSceneGenerator::onTouchesBegan, this);
			this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
			this->unschedule(schedule_selector(GameSceneGenerator::TouchCallbacks));
		}
		
	}
	
}

//Slider for Additional Velocity of the player's marble
void GameSceneGenerator::sliderEvent(Ref *pSender, Slider::EventType type)
{
	if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
	{
		Slider* slider = dynamic_cast<Slider*>(pSender);
		int percent = slider->getPercent();
		SetIncreasedVelocity(percent * 4);
	}
}

//Next Level method
void GameSceneGenerator::TimerDelayToNextLevel(float delaytime)
{
	if (Level == 10)
	{
		auto scene = GameOverScene::createScene(Level, "All Levels Cleared");
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
	else
	{
		auto scene = LevelUpScene::createScene(Level + 1);
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
	
}

//Detects marbles if all of them are cleared
void GameSceneGenerator::isMarblesCleared(float delaytime)
{
	
	for (int i = 1; i < Level + 2; i++)
	{
		if (Level == 10)
		{
			if (flags[Level - 2] == 1)
			{
				bool confirmation = true;
				isMarblesClearedConfirmation(confirmation);
			}
			else
			{
				bool confirmation = false;
				isMarblesClearedConfirmation(confirmation);
			}
		}
		if (Level == 8 || Level == 9)
		{
			if (flags[Level - 1] == 1)
			{
				bool confirmation = true;
				isMarblesClearedConfirmation(confirmation);
			}
			else
			{
				bool confirmation = false;
				isMarblesClearedConfirmation(confirmation);
			}
		}
		if (Level == 6 || Level == 7)
		{
			if (flags[Level] == 1)
			{
				bool confirmation = true;
				isMarblesClearedConfirmation(confirmation);
			}
			else
			{
				bool confirmation = false;
				isMarblesClearedConfirmation(confirmation);
			}
		}
		
		else
		{
			if (flags[Level + 1] == 1)
			{
				bool confirmation = true;
				isMarblesClearedConfirmation(confirmation);
			}
			else
			{
				bool confirmation = false;
				isMarblesClearedConfirmation(confirmation);
			}
		}
		
	}



}
//Confirms the isMarbleCleared method then call the NextLevel method if condition is true
void GameSceneGenerator::isMarblesClearedConfirmation(bool confirmation)  
{
	if (confirmation == true)
	{
		
		//for Game Progress auto saving
		{
			const char* GameProgess[10] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "10" };
			#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
			__Dictionary* dictionary = Dictionary::createWithContentsOfFile("/data/data/leandro.gecozo.ballshat/GameData.xml");
			#endif
			#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
			__Dictionary* dictionary = Dictionary::createWithContentsOfFile("E:/GameData.xml");
			#endif
			FileOperation::saveFile(GameProgess[Level - 1]);
		}
		TouchDisabler = true;
		auto Cleared = MenuItemImage::create("Buttons/Cleared.png", "Buttons/Cleared.png");
		Cleared->setPosition(Point(visibleSize.width / 2 + origin.x - 40, visibleSize.height / 2 + origin.y));
		float SizeX = visibleSize.width / (visibleSize.width * 0.1);
		float SizeY = visibleSize.height / (visibleSize.height * 0.1);
		Cleared->setScale(SizeX * SizeY * 0.0090);
		this->addChild(Cleared);


		//delays 3 seconds before proceeding to the next level
		this->scheduleOnce(schedule_selector(GameSceneGenerator::TimerDelayToNextLevel), 3.00f);
	}
}

//Capture the status if the ball is gone
void GameSceneGenerator::captureBallStatus(int flag)
{
		flags[flagIndex] = flag;
		flagIndex++;
}
//method responsible for method collision detection and sounds effects
bool GameSceneGenerator::OnContactbegin(cocos2d::PhysicsContact &contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();

	//for Player's marble Hole collision
	if ((1 == a->getCollisionBitmask() && 12 == b->getCollisionBitmask()) || (12 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
	{
		CCLOG("Collision has occured");
		this->removeChild(Ball[0], true);
		Ball[0] = nullptr;
		
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/Hole.mp3");
		auto scene = GameOverScene::createScene(Level, "Your Ball Got Sucked");
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
	//for EdgeBox collision
	for (int i = 0; i < Level + 4;)
	{	
		if ((i == a->getCollisionBitmask() && 13 == b->getCollisionBitmask()) || (13 == a->getCollisionBitmask() && i == b->getCollisionBitmask()))
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/tock.mp3");
		}
		i++;
	}
	//for hole collision
	for (int i = 1; i < Level + 3;)
	{
		if ((i + 1 == a->getCollisionBitmask() && 12 == b->getCollisionBitmask()) || (12 == a->getCollisionBitmask() && i + 1 == b->getCollisionBitmask()))
		{
			CCLOG("Collision has occured");
			this->removeChild(Ball[i], true);
			int flag = 1;
			captureBallStatus(flag);
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/Hole.mp3");
		}
		i++;
	}

	//For BallHit collision
	for (int i = 2; i < 11;)
	{
		static 	int combination = 1;
		if ((i == a->getCollisionBitmask() && combination == b->getCollisionBitmask()) || (combination == a->getCollisionBitmask() && i == b->getCollisionBitmask()))
		{
			CCLOG("Collision has occured");
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/BallHit2.wav");
		}
		i++;
		if (i == 11)
		{
			i = 2;
			combination++;
		}
		if (combination == 11)
		{
			combination = 1;
			break;
		}
	}
	return true;
}


//This method locates the touch point of the player
Point GameSceneGenerator::touchToPoint(cocos2d::Touch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}

//This method detects if the touch point reaches the area of the Player's marble
bool GameSceneGenerator::isTouchingSprite(cocos2d::Touch* touch)
{
	// here's one way, but includes the rectangular white space around our sprite
	//return CGRectContainsPoint(this->sprite->boundingBox(), this->touchToPoint(touch));

	// this way is more intuitive for the user because it ignores the white space.
	// it works by calculating the distance between the sprite's center and the touch point,
	// and seeing if that distance is less than the sprite's radius

	return (Ball[0]->getPosition().getDistance(this->touchToPoint(touch)) < 20.0f);


}

//touch began method
void GameSceneGenerator::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
{
	if (Ball[0] == nullptr || TouchDisabler == true)
	{
		return;
	}
	// reset touch offset
	this->touchOffset = Point::ZERO;
	for (auto touch : touches)
	{
		// stop any existing actions
		if (Ball[0] == nullptr || TouchDisabler == true)
		{
			break;
		}
		stopPlayerBall();
		//prevents the player's ball from relocating greater than 400 Pixels of range
		if (touch->getLocation().x < 400)
		{
			CCLOG("Overpassed! ");
			Ball[0]->setPosition(Point(visibleSize.width / 1 + origin.x - 27, visibleSize.height / 2 + origin.y));
			Ball[0]->stopAllActions();
			float SizeX = visibleSize.width / (visibleSize.width * 0.073);
			float SizeY = visibleSize.height / (visibleSize.height * 0.11);
			Ball[0]->setScale((SizeX * SizeY) * 0.0080);
			auto spriteBody = PhysicsBody::createCircle((SizeX * SizeY) * 0.140, PhysicsMaterial(0, 1, 0));
			Ball[0]->setPhysicsBody(spriteBody);
			// animate letting go of the sprite
			Ball[0]->runAction(Sequence::create(ScaleBy::create(0.125f, 1.111f), ScaleBy::create(0.125f, 0.9f), nullptr));
		
		}
		else
		{
			// if this touch is within our sprite's boundary
			if (touch && this->isTouchingSprite(touch))
			{
				// calculate offset from sprite to touch point
				this->touchOffset = Ball[0]->getPosition() - this->touchToPoint(touch);
			}
			
			//Get lauched data from touches ended
			bool isLaunched = GetLaunched();
			//if condition is true, decrements the ball counter by 1 until it reaches 0, this means no charges left
			//for the player to launch.
			if (isLaunched == true)
			{
				BallCounter--;
				SetLaunched(false);
			}
			if (BallCounter == 0)
			{
				auto scene = GameOverScene::createScene(Level, "Out of Balls");
				Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
			}
			//else reposition the player's ball back to its specified range which is less than 400 pixels X axis
			else
			{
				if (Ball[0]->getPosition().x < 400)
				{
					
					Ball[0]->setPosition(Point(touch->getLocation().x, touch->getLocation().y));
					Ball[0]->stopAllActions();
					float SizeX = visibleSize.width / (visibleSize.width * 0.073);
					float SizeY = visibleSize.height / (visibleSize.height * 0.11);
					Ball[0]->setScale((SizeX * SizeY) * 0.0080);
					auto spriteBody = PhysicsBody::createCircle((SizeX * SizeY) * 0.140, PhysicsMaterial(0, 1, 0));
					Ball[0]->setPhysicsBody(spriteBody);
					// animate letting go of the sprite
					Ball[0]->runAction(Sequence::create(ScaleBy::create(0.125f, 1.111f), ScaleBy::create(0.125f, 0.9f), nullptr));
					
				}
				else
				{
				
					Ball[0]->stopAllActions();
					auto action = MoveTo::create(0.3f, Point(touch->getLocation().x, touch->getLocation().y));
					Ball[0]->runAction(EaseCircleActionOut::create(action));
					float SizeX = visibleSize.width / (visibleSize.width * 0.073);
					float SizeY = visibleSize.height / (visibleSize.height * 0.11);
					Ball[0]->setScale((SizeX * SizeY) * 0.0080);
					auto spriteBody = PhysicsBody::createCircle((SizeX * SizeY) * 0.140, PhysicsMaterial(0, 1, 0));
					Ball[0]->setPhysicsBody(spriteBody);
					// animate letting go of the sprite
					Ball[0]->runAction(Sequence::create(ScaleBy::create(0.125f, 1.111f), ScaleBy::create(0.125f, 0.9f), nullptr));
					
				}
				
			}

		}
		
	}
}

//touches moved method
void GameSceneGenerator::onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
{
	if (Ball[0] == nullptr || TouchDisabler == true)
	{
		return;
	}
	for (auto touch : touches)
	{
		if (Ball[0] == nullptr || TouchDisabler == true)
		{
			break;
		}
		// set the new sprite position
		if (touch && touchOffset.x && touchOffset.y)
		{
			Ball[0]->setPosition(this->touchToPoint(touch) + this->touchOffset);
			//Cancel the relocation of the Player's marble if the starting range exeeds 400
			if (touch->getLocation().x < 400)
			{
				onTouchesCanceled();
			}
		}
		//	CCLOG("onTouchMoved x = %f, y = %f,", touch->getLocation().x, touch->getLocation().y);
	}

}

//touches ended method
void GameSceneGenerator::onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
{
	if (Ball[0] == nullptr || TouchDisabler == true)
	{
		return;
	}
	for (auto touch : touches)
	{
		if (Ball[0] == nullptr || TouchDisabler == true)
		{
			break;
		}
		if (touch->getLocation().x > 400)
		{
			if (Ball[0] == nullptr || TouchDisabler == true)
			{
				break;
			}
			if (touch && touchOffset.x && touchOffset.y)
			{
				if (Ball[0] == nullptr || TouchDisabler == true)
				{
					break;
				}
				//sound effect after launching the player's marble
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/LaunchBall6.mp3");
		
				//Physics of Player's marble including Physics Body, Velocity and bitmask
				float SizeX = visibleSize.width / (visibleSize.width * 0.073);
				float SizeY = visibleSize.height / (visibleSize.height * 0.11);
				Ball[0]->setScale((SizeX * SizeY) * 0.0080);
				auto spriteBody = PhysicsBody::createCircle((SizeX * SizeY) * 0.140, PhysicsMaterial(0, 1, 0));

				spriteBody->setCollisionBitmask(1);
				spriteBody->setContactTestBitmask(true);
				Ball[0]->setPhysicsBody(spriteBody);

				float AdditionalPower = GetIncreasedVelocity();
				float FinalVelocity = -200 - AdditionalPower;
				spriteBody->setVelocity(Vect(FinalVelocity * 2, 0));
				spriteBody->setVelocityLimit(1500);
				double Decelerate = 1.700000;
				spriteBody->setLinearDamping(Decelerate);

				//removes the charges after launcing
				this->removeChild(Charges[index--], true);

				//set the Player's marble launched to true
				SetLaunched(true);
			}
		}
		else
		{
			break;
		}
	}
	
}

//StopPlayerBall method stops the ball and returning it to 0 velocity
void GameSceneGenerator::stopPlayerBall()
{
	float SizeX = visibleSize.width / (visibleSize.width * 0.073);
	float SizeY = visibleSize.height / (visibleSize.height * 0.11);
	Ball[0]->setScale((SizeX * SizeY) * 0.0080);
	auto spriteBody = PhysicsBody::createCircle((SizeX * SizeY) * 0.140, PhysicsMaterial(0, 1, 0));
	spriteBody->setCollisionBitmask(1);
	spriteBody->setContactTestBitmask(true);
	Ball[0]->setPhysicsBody(spriteBody);
	spriteBody->setVelocity(Vect(0, 0));
}

//Cancel the touch of the Player's ball if it exeeds the range threshold
void GameSceneGenerator::onTouchesCanceled()
{
	
	// set the new sprite position


	Ball[0]->setPosition(Point(visibleSize.width / 1 + origin.x - 27, visibleSize.height / 2 + origin.y));
	// stop any existing actions and reset the scale
	Ball[0]->stopAllActions();
	float SizeX = visibleSize.width / (visibleSize.width * 0.073);
	float SizeY = visibleSize.height / (visibleSize.height * 0.11);
	Ball[0]->setScale((SizeX * SizeY) * 0.0080);
	auto spriteBody = PhysicsBody::createCircle((SizeX * SizeY) * 0.140, PhysicsMaterial(0, 1, 0));
	// animate letting go of the sprite
	Ball[0]->runAction(Sequence::create(ScaleBy::create(0.125f, 1.111f), ScaleBy::create(0.125f, 0.9f), nullptr));

}

//Pass the Marble Object data for assing child node to parent node
cocos2d::Sprite* GameSceneGenerator::Marbles(cocos2d::Sprite* ball)
{
	cocos2d::Sprite* Ball = ball;
	return Ball;
}









