#include "Ball.h"
#include "DefineBitmask.h"

bool Ball::init()
{
    if (!Sprite::initWithFile("CloseNormal.png"))
    {
        return false;
    }

    PhysicsMaterial material = PhysicsMaterial(1, 0, 1);
    auto body = PhysicsBody::createCircle(_contentSize.width / 2, material);
    
    body->setCategoryBitmask(DefineBitmask::BALL);
    body->setCollisionBitmask(DefineBitmask::WALL | DefineBitmask::BALL);
    body->setContactTestBitmask(DefineBitmask::WALL);

    body->setMass(0.1f);
    this->setPhysicsBody(body);

    auto listener = EventListenerPhysicsContact::create();
    listener->onContactBegin = CC_CALLBACK_1(Ball::onContactBegin, this);
    listener->onContactPreSolve = CC_CALLBACK_1(Ball::onContactPreSolve, this);
    listener->onContactPostSolve = CC_CALLBACK_1(Ball::onContactPostSolve, this);
    listener->onContactSeparate = CC_CALLBACK_1(Ball::onContactSeparate, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

bool Ball::onContactBegin(PhysicsContact& contact)
{
    log("onContactBegin");
    return true;
}

bool Ball::onContactPreSolve(PhysicsContact& contact)
{
    log("onContactPreSolve");
    return true;
}

bool Ball::onContactPostSolve(PhysicsContact& contact)
{
    log("onContactPostSolve");
    return true;
}

bool Ball::onContactSeparate(PhysicsContact& contact)
{
    log("onContactSeparate");
    return true;
}
