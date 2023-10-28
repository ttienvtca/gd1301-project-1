#include "DemoSingleton.h"

DemoSingleton* DemoSingleton::_instance;

DemoSingleton::DemoSingleton()
{
    character = Sprite::create("HelloWorld.png");
}

DemoSingleton* DemoSingleton::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new DemoSingleton();
    }
    return _instance;
}

Sprite* DemoSingleton::getCharacter()
{
    return character;
}

void DemoSingleton::show()
{
    cocos2d::log("demo singleton");
}
