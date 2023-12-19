#include "HelloWorldScene.h"
#include "DemoSingleton.h"
#include "Input/KeyboardInput.h"
#include "Entity/EntityInfo.h"
#include "Character/Character.h"
#include "Enemy/Enemy.h"
#include "Bullet/Bullet.h"

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
    if ( !Scene::initWithPhysics() )
    {
        return false;
    }
    this->getPhysicsWorld()->setGravity(Vec2::ZERO);
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // character
    EntityInfo* characterInfo = new EntityInfo(1, "character");
    _character = Character::create(characterInfo);
    _character->setPosition(visibleSize / 2);

    _map = GameMap::create("Map/map-demo.tmx");
    TMXObjectGroup* objGroup = _map->getObjectGroup("SpawnPoint");
    ValueMap charPoint = objGroup->getObject("CharacterSpawnPoint");
    
    // mouse input
    auto mouseListener = EventListenerMouse::create();
    mouseListener->onMouseDown = CC_CALLBACK_1(HelloWorld::mouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);


    // enemy
    auto enemy = Enemy::create(new EntityInfo(1, "ice-cube"));
    enemy->setPosition(Vec2(500, 500));

    Vec2 position;
    position.x = charPoint["x"].asFloat();
    position.y = charPoint["y"].asFloat();

    _character->setPosition(position);

    this->addChild(_character, 1);
    this->addChild(enemy, 1);
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

    _defaultCamera->setPosition(nextPostion);
}

void HelloWorld::onEnter()
{
    Scene::onEnter();
    if (KeyboardInput::getInstance()->getParent() != nullptr)
        KeyboardInput::getInstance()->removeFromParent();

    this->addChild(KeyboardInput::getInstance());
}

void HelloWorld::mouseDown(EventMouse* event)
{
    Vec2 posInput = event->getLocationInView();

    auto camBoundingBox = Camera::getDefaultCamera()->getBoundingBox();
    Vec2 worldPos = camBoundingBox.origin - camBoundingBox.size / 2 + posInput;

    Vec2 direction = worldPos - _character->getPosition();
    direction.normalize();
    auto bullet = Bullet::create("1");
    bullet->setPosition(_character->getPosition());
    bullet->getPhysicsBody()->setVelocity(direction * 100);

    this->addChild(bullet, 1);
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
