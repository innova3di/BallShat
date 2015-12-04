#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__

#include "cocos2d.h"


class GameOverScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene(int level, std::string message);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
	CREATE_FUNC(GameOverScene);

	void PlayErrorSoundEffect(float delaytime);

private:
	void GoToGameScene(cocos2d::Ref *sender);
	void GoToMainMenuScene(cocos2d::Ref *sender);
	void preloadSounds();
};

#endif // __GAME_OVER_SCENE_H__
