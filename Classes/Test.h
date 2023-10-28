#ifndef __TEST_H__
#define __TEST_H__

#include "cocos2d.h"
#include "HorizontalLayout.h"

USING_NS_CC;

class Test : public Sprite
{
public:
	static Test* createWithFile(std::string path);
	bool init() override;
	void addChild(Node* child) override;
	CREATE_FUNC(Test);

public:
	HorizontalLayout* _horizontalLayout;
};

#endif // !__TEST_H__
