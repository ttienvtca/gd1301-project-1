#include "Character.h"
#include "Utilities/AnimationUtilities.h"

bool Character::loadAnimations()
{
    AnimationUtils::loadSpriteFrameCache("Character/", _info->_entityName + "-idle");
    AnimationUtils::loadSpriteFrameCache("Character/", _info->_entityName + "-move");
    AnimationUtils::loadSpriteFrameCache("Character/", _info->_entityName + "-attack");

    AnimationUtils::createAnimation(_info->_entityName + "-idle", 1.0f);
    AnimationUtils::createAnimation(_info->_entityName + "-move", 1.0f);
    AnimationUtils::createAnimation(_info->_entityName + "-attack", 1.0f);

    auto idle = AnimationCache::getInstance()->getAnimation(_info->_entityName + "-idle");
    auto move = AnimationCache::getInstance()->getAnimation(_info->_entityName + "-move");
    auto attack = AnimationCache::getInstance()->getAnimation(_info->_entityName + "-attack");

    _model = Sprite::createWithSpriteFrameName(_info->_entityName + "-idle (1)");

    return true;
}
