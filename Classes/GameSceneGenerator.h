#pragma once


#include "cocos2d.h"
#include <vector>
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocos2d::ui;
using cocos2d::Point;


class GameSceneGenerator : public cocos2d::Layer
{
public:

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene(int level);

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameSceneGenerator);

	void preloadSounds();

	/// Returns the Cocos2d position of the touch
	Point touchToPoint(cocos2d::Touch* touch);

	/// Returns true if the touch is within the boundary of our sprite
	bool isTouchingSprite(cocos2d::Touch* touch);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// we are multi-touch enabled, so we must use the ccTouches functions
	// vs the ccTouch functions
	void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
	void onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
	void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
	void onTouchesCanceled();

	void stopPlayerBall();

	void createPlayersBall();

	void createRocks(int level);

	void createMarbleWithtDelay(float delaytime);
	void createCharges(float delaytime);

	void isMarblesCleared(float delaytime);
	void isMarblesClearedConfirmation(bool confirmation);
	void captureBallStatus(int flag);


	void SetLaunched(bool launched)
	{
		Launched = launched;

	}
	bool GetLaunched()
	{
		return Launched;
	}

	void playBGM(float delaytime);
protected:
	cocos2d::Sprite* Ball[20];
	cocos2d::Sprite* Charges[40];
	
	
private:
	cocos2d::Sprite* Rock[10];
	bool Launched = false;
	int BallCounter = 0;
	int index = 0;
	int flags[12];
	int flagIndex = 0;
	float IncreasedVelocity = 0;
	bool SpawnChargesDone = false;
	bool TouchDisabler = false;

	void TouchCallbacks(float delaytime);
	void sliderEvent(Ref *pSender, Slider::EventType type);

	void SetIncreasedVelocity(int Increase)
	{
		IncreasedVelocity = Increase;
	}
	float GetIncreasedVelocity()
	{
		return IncreasedVelocity;
	}
	void TimerDelayToNextLevel(float delaytime);



	cocos2d::Sprite* Marbles(cocos2d::Sprite* ball);

	cocos2d::PhysicsWorld *sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld *world)
	{
		sceneWorld = world;
	}

	bool OnContactbegin(cocos2d::PhysicsContact &contact);

	cocos2d::Point touchOffset;


};