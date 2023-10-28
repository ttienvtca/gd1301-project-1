#ifndef __DEMO_SINGLETON_H__
#define __DEMO_SINGLETON_H__

#include "cocos2d.h"

USING_NS_CC;

class DemoSingleton
{
private:
	static DemoSingleton* _instance;
	DemoSingleton();

public:
	static DemoSingleton* getInstance();

private:

	Sprite* character;

public:
	Sprite* getCharacter();
	void show();
};

#endif // !__DEMO_SINGLETON_H__
