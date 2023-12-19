#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

USING_NS_CC;

class Bullet : public Node
{
public:
	static Bullet* create(std::string bulletName);
	virtual bool init(std::string bulletName);
protected:
	Sprite* _model;

	bool onContactBegin(PhysicsContact& contact);
};

#endif // !__BULLET_H__
