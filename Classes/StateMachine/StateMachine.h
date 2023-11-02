#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "cocos2d.h"
USING_NS_CC;

#include "State.h"
#include "Entity/Entity.h"

class StateMachine : public Node
{
public:
	static StateMachine* create(Entity* owner);
	virtual bool init(Entity* owner);
	void addState(std::string stateName, State* state);
	void removeState(std::string stateName);
	void setCurrentState(std::string stateName);
protected:
	std::map<std::string, State*> _states;
	std::string _currentState;

	Entity* _owner;
protected:
	void update(float dt) override;

	void onEnter() override;
};

#endif // !__STATE_MACHINE_H__
