#include "DemoPhysics.h"
#include "DefineBitmask.h"

bool DemoPhysics::init()
{
	if (!Scene::initWithPhysics())
	{
		return false;
	}

	this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	this->getPhysicsWorld()->setGravity(Vec2(0, -400));
	// create edge box

	PhysicsMaterial material = PhysicsMaterial(1, 0, 1);
	auto edgeBody = PhysicsBody::createEdgeBox(
		Director::getInstance()->getVisibleSize(), material, 10);
	edgeBody->setGravityEnable(false);
	edgeBody->setCategoryBitmask(DefineBitmask::WALL);
	edgeBody->setCollisionBitmask(DefineBitmask::BALL);
	edgeBody->setContactTestBitmask(DefineBitmask::BALL);

	auto edgeNode = Node::create();
	edgeNode->setPhysicsBody(edgeBody);
	edgeNode->setPosition(Director::getInstance()->getVisibleSize() / 2);
	

	// create character
	_character = Ball::create();
	_character->setPosition(Director::getInstance()->getVisibleSize() / 2);

	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(DemoPhysics::mouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);


	this->addChild(_character);
	this->addChild(edgeNode);
    return true;
}

void DemoPhysics::mouseDown(EventMouse* event)
{
	log("mouse down");
	Vec2 direction = event->getLocationInView() - _character->getPosition();
	direction.normalize();

	_character->getPhysicsBody()->applyForce(Vec2(0, 1) * 3000);
}
