#include "Bullet.h"
#include "DefineBitmask.h"
#include "IDamageable.h"

Bullet* Bullet::create(std::string spritePath)
{
	auto newObject = new Bullet();
	if (newObject && newObject->init(spritePath))
	{
		newObject->autorelease();
		return newObject;
	}

	CC_SAFE_DELETE(newObject);
	return nullptr;
}

bool Bullet::init(std::string bulletName)
{
	if (!Node::init())
	{
		return false;
	}

	_model = Sprite::create("Bullet/" + bulletName + ".png");
	this->addChild(_model);
	PhysicsMaterial material = PhysicsMaterial(1, 0, 1);
	auto body = PhysicsBody::createCircle(_model->getContentSize().height / 2, material);

	body->setCategoryBitmask(DefineBitmask::BULLET);
	body->setCollisionBitmask(DefineBitmask::CHARACTER | DefineBitmask::ENEMY);
	body->setContactTestBitmask(DefineBitmask::CHARACTER | DefineBitmask::ENEMY);

	this->setPhysicsBody(body);


	bool onContactBegin(PhysicsContact & contact);
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = CC_CALLBACK_1(Bullet::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

bool Bullet::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	auto target = (nodeA == this) ? (nodeB) : (nodeA);

	auto damageable = dynamic_cast<IDamageable*>(target);
	if (damageable != nullptr)
	{
		damageable->takeDamage(10);
	}

	this->removeFromParentAndCleanup(true);

	return false;
}
