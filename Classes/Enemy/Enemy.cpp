#include "Enemy.h"
#include "Utilities/AnimationUtilities.h"
#include "DefineBitmask.h"

Enemy* Enemy::create(EntityInfo* info)
{
    auto newObject = new Enemy();
    if (newObject && newObject->init(info))
    {
        newObject->autorelease();
        return newObject;
    }

    CC_SAFE_DELETE(newObject);
    return nullptr;
}

bool Enemy::init(EntityInfo* info)
{
    if (!Entity::init(info))
    {
        return false;
    }

    auto animationIdle = AnimationCache::getInstance()
        ->getAnimation(_info->_entityName + "-idle");
    auto idle = Animate::create(animationIdle);

    _model = Sprite::createWithSpriteFrame(animationIdle->getFrames().at(0)->getSpriteFrame());
    _model->runAction(RepeatForever::create(idle));

    PhysicsMaterial material = PhysicsMaterial(1, 0, 1);
    auto body = PhysicsBody::createCircle(_model->getContentSize().height / 2, material);
    body->setRotationEnable(false);
    body->setCategoryBitmask(DefineBitmask::ENEMY);
    body->setCollisionBitmask(DefineBitmask::CHARACTER | DefineBitmask::BULLET);
    body->setContactTestBitmask(DefineBitmask::BULLET);

    this->setPhysicsBody(body);

    this->addChild(_model);

    return true;
}

void Enemy::takeDamage(int dame)
{
    log("enemy take damage: %d", dame);
}

bool Enemy::loadAnimations()
{
    std::string filePath = "Enemy/" + _info->_entityName;
    AnimationUtils::loadSpriteFrameCache(filePath, "-idle");
    AnimationUtils::loadSpriteFrameCache(filePath, "-run");
    AnimationUtils::loadSpriteFrameCache(filePath, "-attack");

    AnimationUtils::createAnimation(_info->_entityName + "-idle", 1.0f);
    AnimationUtils::createAnimation(_info->_entityName + "-run", 1.0f);
    AnimationUtils::createAnimation(_info->_entityName + "-attack", 1.0f);

    return true;
}
