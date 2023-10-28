#include "Test.h"

Test* Test::createWithFile(std::string path)
{
    auto newObject = new Test();
    if (newObject == nullptr || !newObject->initWithFile(path))
    {
        return nullptr;
    }
    newObject->autorelease();
    return newObject;
}

bool Test::init()
{
    if (!Sprite::init())
    {
        log("Init Test failed!");
        return false;
    }

    _horizontalLayout = HorizontalLayout::create();

    this->addChild(_horizontalLayout);
    return true;
}

void Test::addChild(Node* child)
{
    Sprite::addChild(child);
    _horizontalLayout->alignment();
}
