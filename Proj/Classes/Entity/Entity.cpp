#include "Entity.h"
#include "Utilities/AnimationUtilities.h"

Entity* Entity::create(EntityInfo* info)
{
    auto newObject = new Entity();
    if (newObject != nullptr && newObject->init(info))
    {
        newObject->autorelease();
        return newObject;
    }
    CC_SAFE_DELETE(newObject);
    return nullptr;
}

bool Entity::init(EntityInfo* info)
{
    if (!Node::init())
    {
        log("Init Entity failed!");
        return false;
    }

    loadAnimations();

    this->addChild(_model);
    return true;
}

bool Entity::loadAnimations()
{
    return true;
}
