#include "CharacterAttackState.h"

void CharacterAttackState::enterState(Entity* owner)
{
	State::enterState(owner);
	auto animation = AnimationCache::getInstance()
		->getAnimation(_owner->getEntityInfo()->_entityName + "-attack");
	auto ani = RepeatForever::create(Animate::create(animation));

	_owner->getModel()->runAction(ani);

	_timeAttack = 1.0f;
	_elapsedTime = 0;
}

std::string CharacterAttackState::updateState()
{
	_elapsedTime += Director::getInstance()->getAnimationInterval();
	if (_elapsedTime >= _timeAttack)
	{
		return "idle";
	}

	return "attack";
}

void CharacterAttackState::exitState()
{
	State::exitState();
}
