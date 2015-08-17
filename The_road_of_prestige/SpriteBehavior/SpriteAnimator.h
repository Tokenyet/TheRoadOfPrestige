#ifndef  _SPRITE_ANIMATOR_H_
#define  _SPRITE_ANIMATOR_H_

#include "cocos2d.h"
using namespace cocos2d;

// ===================================================================================
// This class is to help sprite to create animation for Sprite.runAction.
// 
// Feature:
// SetAnimation : SetAnimation("attack",5,0.3)
//
// Requirement:
// Need a .plist with same filename .png on the same folder
// Need a order png name [ name0.png ~ nameXXX.png ] in the .plist.
// -- 
// Usage:
// 	SpriteAnimator attackAnimator("human/bat.plist");
//  attackAnimator.SetAnimation("attack", 6, 0.3);
//  auto tempAnimate = attackAnimator.GetSpecifiedAnimate("attack");
//  auto bats = Sprite::create();
//  bats->runAction(Repeat::create(tempAnimate, 10));
// ***********************************************************************************
// Maintain by Dowen.
// ===================================================================================

class SpriteAnimator
{
public:
	SpriteAnimator(const char* path);
	~SpriteAnimator();
	// Create pointer with class
    static SpriteAnimator* Create(const char* path);
	// name  : png name in .plist
	// amount: how many .png with name
	// delay : time to change frame
	void SetAnimation(const char* name, int amount, float delay);
	// return Animation you want
	Animate* GetSpecifiedAnimate(const char* name);
protected:
	// Spritsheet store in this cache
	SpriteFrameCache* _cache;
	// all animation work are in this stack
	//Map<String, Vector<SpriteFrame*>> _namedActions;
	Map<const char*, Animate*> _namedActions;

private:
	const char* _plist;
};

#endif
