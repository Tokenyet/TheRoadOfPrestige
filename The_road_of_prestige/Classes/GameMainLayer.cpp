#include "GameMainLayer.h"


// on "init" you need to initialize your instance
bool GameMainLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameMainLayer::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
	// load the Sprite Sheet
	auto spritecache = SpriteFrameCache::getInstance();
	// the .plist file can be generated with any of the tools mentioned below
	spritecache->addSpriteFramesWithFile("human/bat.plist");

	Vector<SpriteFrame*>attackFrames;
	attackFrames.reserve(6);
	attackFrames.pushBack(spritecache->getSpriteFrameByName("attack0.png"));
	attackFrames.pushBack(spritecache->getSpriteFrameByName("attack1.png"));
	attackFrames.pushBack(spritecache->getSpriteFrameByName("attack2.png"));
	attackFrames.pushBack(spritecache->getSpriteFrameByName("attack3.png"));
	attackFrames.pushBack(spritecache->getSpriteFrameByName("attack4.png"));
	attackFrames.pushBack(spritecache->getSpriteFrameByName("attack5.png"));

	animation = Animation::createWithSpriteFrames(attackFrames, 0.3);

	SpriteAnimator attackAnimator("human/bat.plist");
	attackAnimator.SetAnimation("attack", 6, 0.3);
	auto tempAnimate = attackAnimator.GetSpecifiedAnimate("attack");


	bats = Sprite::create();
	//bats->runAction(Repeat::create(Animate::create(animation),10));
	bats->runAction(Repeat::create(tempAnimate,10));

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(GameMainLayer::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameMainLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "GameMainLayer" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//bats->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	//this->addChild(bats, 0);
    
    return true;
}


// Implementation of the keyboard event callback function prototype
void GameMainLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	/*if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
		if (bats->numberOfRunningActions() == 0)
		{
			auto spritecache = SpriteFrameCache::getInstance();
			spritecache->addSpriteFramesWithFile("human/bat.plist");
			Vector<SpriteFrame*>attackFrames;
			attackFrames.reserve(6);
			attackFrames.pushBack(spritecache->getSpriteFrameByName("attack0.png"));
			attackFrames.pushBack(spritecache->getSpriteFrameByName("attack1.png"));
			attackFrames.pushBack(spritecache->getSpriteFrameByName("attack2.png"));
			attackFrames.pushBack(spritecache->getSpriteFrameByName("attack3.png"));
			attackFrames.pushBack(spritecache->getSpriteFrameByName("attack4.png"));
			attackFrames.pushBack(spritecache->getSpriteFrameByName("attack5.png"));
			//animation = Animation::createWithSpriteFrames(attackFrames, 0.3);
			auto temp = Animate::create(animation);
			bats->runAction(temp);
		}*/
}

void GameMainLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	/*if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
		bats->stopAllActions();*/
}

void GameMainLayer::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
