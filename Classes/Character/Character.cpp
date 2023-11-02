#include "Character.h"
#include "Utilities/AnimationUtilities.h"
#include "Input/KeyboardInput.h"
#include "State/CharacterAttackState.h"
#include "State/CharacterIdleState.h"
#include "State/CharacterRunState.h"

Character* Character::create(EntityInfo* info)
{
    auto newObject = new Character();
    if (newObject && newObject->init(info))
    {
        newObject->autorelease();
        return newObject;
    }

    CC_SAFE_DELETE(newObject);
    return nullptr;
}

bool Character::init(EntityInfo* info)
{
    if (!Entity::init(info))
    {
        log("Init Character failed!");
        return false;
    }

    auto animationIdle = AnimationCache::getInstance()
        ->getAnimation(_info->_entityName + "-idle");
    auto idle = Animate::create(animationIdle);

    _model = Sprite::createWithSpriteFrame(animationIdle->getFrames().at(0)->getSpriteFrame());
    _model->runAction(RepeatForever::create(idle));

    this->scheduleUpdate();

    KeyboardInput::getInstance()->addKey(EventKeyboard::KeyCode::KEY_SPACE);

    _stateMachine = StateMachine::create(this);
    _stateMachine->addState("idle", new CharacterIdleState());
    _stateMachine->addState("attack", new CharacterAttackState());
    _stateMachine->addState("run", new CharacterRunState());
    _stateMachine->setCurrentState("idle");

    this->addChild(_model);
    this->addChild(_stateMachine);
    return true;
}

bool Character::loadAnimations()
{
    std::string filePath = "Character/" + _info->_entityName;
    AnimationUtils::loadSpriteFrameCache(filePath, "-idle");
    AnimationUtils::loadSpriteFrameCache(filePath, "-run");
    AnimationUtils::loadSpriteFrameCache(filePath, "-attack");

    AnimationUtils::createAnimation(_info->_entityName + "-idle", 1.0f);
    AnimationUtils::createAnimation(_info->_entityName + "-run", 1.0f);
    AnimationUtils::createAnimation(_info->_entityName + "-attack", 1.0f);


    return true;
}

void Character::update(float dt)
{
    //if (KeyboardInput::getInstance()->getKey(EventKeyboard::KeyCode::KEY_1))
    //{
    //    auto animAttack = AnimationCache::getInstance()->getAnimation(_info->_entityName + "-attack");
    //    auto attack = Animate::create(animAttack);
    //    _model->stopAllActions();
    //    _model->runAction(RepeatForever::create(attack));
    //}
    //else if(KeyboardInput::getInstance()->getKey(EventKeyboard::KeyCode::KEY_2))
    //{
    //    auto animIdle = AnimationCache::getInstance()->getAnimation(_info->_entityName + "-idle");
    //    auto idle = Animate::create(animIdle);
    //    _model->stopAllActions();
    //    _model->runAction(RepeatForever::create(idle));
    //}
    //else if(KeyboardInput::getInstance()->getKey(EventKeyboard::KeyCode::KEY_3))
    //{
    //    auto animMove = AnimationCache::getInstance()->getAnimation(_info->_entityName + "-move");
    //    auto move = Animate::create(animMove);
    //    _model->stopAllActions();

    //    _model->runAction(RepeatForever::create(move));
    //}

    //switch (_entityState)
    //{
    //case Idle:
    //    // update
    //    KeyboardInput::getInstance()->getDirection() != Vec2::ZERO;
    //    // 
    //    break;
    //case Move:
    //    break;
    //case Attack:
    //    break;
    //default:
    //    break;
    //}
}
