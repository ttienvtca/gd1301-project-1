#include "CharacterIdleState.h"
#include "Input/KeyboardInput.h"

void CharacterIdleState::enterState(Entity* owner)
{
	State::enterState(owner);
	auto animation = AnimationCache::getInstance()
		->getAnimation(_owner->getEntityInfo()->_entityName + "-idle");
	auto ani = RepeatForever::create(Animate::create(animation));

	_owner->getModel()->runAction(ani);
}

std::string CharacterIdleState::updateState()
{
	auto keyboard = KeyboardInput::getInstance();
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

void CharacterIdleState::exitState()
{
	State::exitState();
}
