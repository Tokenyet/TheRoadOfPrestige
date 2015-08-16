#ifndef __GAMEMAIN_SCENE_H__
#define __GAMEMAIN_SCENE_H__

#include "cocos2d.h"
#include "SpriteBehavior\SpriteAnimator.h"
#include "GameMainLayer.h"


using namespace cocos2d;

class GameMainScene : public cocos2d::Scene
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameMainScene);
};
#endif // __GAMEMAIN_SCENE_H__
