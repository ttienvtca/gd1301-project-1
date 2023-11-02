#include "CharacterRunState.h"
#include "Input/KeyboardInput.h"

void CharacterRunState::enterState(Entity* owner)
{
	State::enterState(owner);
	auto animation = AnimationCache::getInstance()
		->getAnimation(_owner->getEntityInfo()->_entityName + "-run");
	auto ani = RepeatForever::create(Animate::create(animation));

	_owner->getModel()->runAction(ani);
}

std::string CharacterRunState::updateState()
{
	// update
	auto keyboard = KeyboardInput::getInstance();
	Vec2 direction = keyboard->getDirection();

	if (direction.x != 0)
		_owner->getModel()->setFlippedX(direction.x < 0);
	Vec2 nextPostion = _owner->getPosition() + 
		direction * 100.0f * Director::getInstance()->getAnimationInterval();
	_owner->setPosition(nextPostion);

	// check
	if (keyboard->getKey(EventKeyboard::KeyCode::KEY_SPACE))
	{
		return "attack";
	}

	if (keyboard->getDirection() == Vec2::ZERO)
	{
		return "idle";
	}

	return "run";
}

void CharacterRunState::exitState()
{
	State::exitState();
}
