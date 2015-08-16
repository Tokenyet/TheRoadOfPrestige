#include "GameMainScene.h"

USING_NS_CC;

Scene* GameMainScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	// auto layer = GameMainScene::create();
	auto gameMainlayer = GameMainLayer::create();

	// add layer as a child to scene
	scene->addChild(gameMainlayer);

	// return the scene
	return scene;
}
