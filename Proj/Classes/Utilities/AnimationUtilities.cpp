#include "AnimationUtilities.h"

bool AnimationUtils::loadSpriteFrameCache(std::string path, std::string fileName)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(path + fileName + ".plist", path + fileName + ".png");
	return true;
}

std::pair<Animation*, int> AnimationUtils::createAnimation(std::string name, float duration)
{
	std::pair<Animation*, int> result;
	int numFrames = 1;
	Vector<SpriteFrame*> frames;

	while (true)
	{
		char buffer[100];
		sprintf(buffer, "./%s (%d)", name.c_str(), numFrames++);
		SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(buffer);
		if (frame == nullptr)
		{
			break;
		}
		frames.pushBack(frame);
	}

	Animation* animation = Animation::createWithSpriteFrames(frames, duration / (float)numFrames);
	result.first = animation;
	result.second = numFrames;

	AnimationCache::getInstance()->addAnimation(animation, name);
	return result;
}

