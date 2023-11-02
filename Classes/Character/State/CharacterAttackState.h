#ifndef __CHARACTER_ATTACK_STATE_H__
#define __CHARACTER_ATTACK_STATE_H__

#include "StateMachine/State.h"

class CharacterAttackState : public State
{
public:
	void enterState(Entity* owner) override;
	std::string updateState() override;
	void exitState() override;

protected:
	float _timeAttack;
	float _elapsedTime;
};

#endif // !__CHARACTER_ATTACK_STATE_H__
