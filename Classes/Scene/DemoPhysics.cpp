#include "DemoPhysics.h"

bool DemoPhysics::init()
{
	if (!Scene::initWithPhysics())
	{
		return false;
	}

	this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	_character = Sprite::create("CloseNormal.png");

	_character->setPosition(Director::getInstance()->getVisibleSize() / 2);

	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(DemoPhysics::mouseDown, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	this->addChild(_character);
    return true;
}

void DemoPhysics::mouseDown(EventMouse* event)
{
	log("mouse down");

	Sprite* bullet = Sprite::create("1.png");

	// create body
	auto body = PhysicsBody::createEdgeBox(bullet->getContentSize());
	bullet->setPhysicsBody(body);

	// shoot
	Vec2 direction = event->getLocationInView() - _character->getPosition();
	direction.normalize();

	bullet->getPhysicsBody()->setVelocity(direction * 10);
	bullet->setPosition(_character->getPosition());

	this->addChild(bullet);

}
