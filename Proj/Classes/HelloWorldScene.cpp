#include "HelloWorldScene.h"
#include "DemoSingleton.h"
#include "Input/KeyboardInput.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // create character


    this->addChild(DemoSingleton::getInstance()->getCharacter());
    // event keyboard
    DemoSingleton::getInstance()->show();
    // update
    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt)
{
    Vec2 direction = KeyboardInput::getInstance()->getDirection();
    DemoSingleton::getInstance()->getCharacter()
        ->setPosition(DemoSingleton::getInstance()
            ->getCharacter()->getPosition() + direction);
}

void HelloWorld::onEnter()
{
    Scene::onEnter();
    if (KeyboardInput::getInstance()->getParent() != nullptr)
        KeyboardInput::getInstance()->removeFromParent();

    this->addChild(KeyboardInput::getInstance());
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
