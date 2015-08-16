#ifndef __GAMEMAIN_LAYER_H__
#define __GAMEMAIN_LAYER_H__

#include "cocos2d.h"
#include "SpriteBehavior\SpriteAnimator.h"


using namespace cocos2d;

class GameMainLayer : public cocos2d::Layer
{
public:

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
	CREATE_FUNC(GameMainLayer);


protected:
		Sprite *bats;
		Animation *animation;
		// keyboard
		void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
		void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};

#endif // __GAMEMAIN_LAYER_H__
