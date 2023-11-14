#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"

USING_NS_CC;

class Ball : public Sprite
{
public:
	bool init();

	CREATE_FUNC(Ball);

private:
	bool onContactBegin(PhysicsContact& contact);
	bool onContactPreSolve(PhysicsContact& contact);
	bool onContactPostSolve(PhysicsContact& contact);
	bool onContactSeparate(PhysicsContact& contact);
};

#endif // !__BALL_H__
