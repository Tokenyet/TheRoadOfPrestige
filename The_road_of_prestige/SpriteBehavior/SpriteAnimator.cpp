#include "SpriteAnimator.h"


SpriteAnimator::SpriteAnimator(const char* path)
{
	_plist = path;
	_cache = SpriteFrameCache::getInstance();
	if (CCFileUtils::getInstance()->isFileExist(path))
		_cache->addSpriteFramesWithFile(path);
	else
        throw "FILE NOT EXIST";
}

SpriteAnimator* SpriteAnimator:: Create(const char* path)
{
	return new SpriteAnimator(path);
}


SpriteAnimator::~SpriteAnimator()
{
	_cache->removeSpriteFramesFromFile(_plist);
	_namedActions.clear();
}


void SpriteAnimator::SetAnimation(const char* name, int amount, float delay)
{
	Vector<SpriteFrame*> animFrames(amount);
	char front[100] = { 0 };
	char str[100] = { 0 };
	for (int i = 0; i < amount; i++)
	{
		strcpy(front, name);
		sprintf(str,"%d.png", i);
		strcat(front, str);
		auto frame = _cache->getSpriteFrameByName(front);
		animFrames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames , delay);
	_namedActions.insert(name,Animate::create(animation));
}

Animate* SpriteAnimator::GetSpecifiedAnimate(const char* name)
{
	return _namedActions.at(name);
}
