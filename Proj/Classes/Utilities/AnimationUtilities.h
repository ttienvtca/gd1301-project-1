#ifndef __ANIMATION_UTILITIES_H__
#define __ANIMATION_UTILITIES_H__

#include "cocos2d.h"

USING_NS_CC;

class AnimationUtils
{
public:
	static bool loadSpriteFrameCache(std::string path, std::string fileName);
	static std::pair<Animation*, int> createAnimation(std::string name, float duration);
};


#endif // !__ANIMATION_UTILITIES_H__
