#ifndef __DEMO_PHYSIC_H__
#define __DEMO_PHYSIC_H__

#include "cocos2d.h"
#include "Ball.h"
USING_NS_CC;

class DemoPhysics : public Scene
{
public:
	bool init();
	CREATE_FUNC(DemoPhysics);

private:
	Ball* _character;
private:
	void mouseDown(EventMouse* event);
};

#endif // !__DEMO_PHYSIC_H__
