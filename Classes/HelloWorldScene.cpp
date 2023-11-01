#include "HelloWorldScene.h"
#include "DemoSingleton.h"
#include "Input/KeyboardInput.h"
#include "Entity/EntityInfo.h"
#include "Character/Character.h"

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

    // character
    EntityInfo* characterInfo = new EntityInfo(1, "character");
    _character = Character::create(characterInfo);
    _character->setPosition(visibleSize / 2);

    _map = GameMap::create("Map/map-demo.tmx");
    TMXObjectGroup* objGroup = _map->getObjectGroup("SpawnPoint");
    ValueMap charPoint = objGroup->getObject("CharacterSpawnPoint");
    

    // 
    auto effects = _map->getObjectGroup("Effects")->getObjects();

    for (auto ef : effects)
    {
        std::string efName = ef.asValueMap()["name"].asString();
        if (efName == "Fire")
        {
            log("fire");
        }
        else if (efName == "Sun")
        {
            log("sun");
        }
    }

    Vec2 position;
    position.x = charPoint["x"].asFloat();
    position.y = charPoint["y"].asFloat();

    _character->setPosition(position);

    this->addChild(_character, 1);
    this->addChild(_map);
    this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt)
{
    Vec2 direction = KeyboardInput::getInstance()->getDirection();

    Vec2 nextPostion = _character->getPosition() + direction * 100.0f * dt;
    int metaID = _map->getMetaAtPos(nextPostion);
    if (metaID == GameMap::MetaRed) return;


    _character->setPosition(nextPostion);
    _defaultCamera->setPosition(nextPostion);
}

void HelloWorld::onEnter()
{
    Scene::onEnter();
    if (KeyboardInput::getInstance()->getParent() != nullptr)
        KeyboardInput::getInstance()->removeFromParent();

    this->addChild(KeyboardInput::getInstance());
}

void HelloWorld::goToSecondScene()
{
    Director::getInstance()->pushScene(Scene::create());
    log("Next second scene");
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
