#include "StateMachine.h"

StateMachine* StateMachine::create(Entity* owner)
{
	auto newObj = new StateMachine();
	if (newObj != nullptr && newObj->init(owner))
	{
		newObj->autorelease();
		return newObj;
	}
	CC_SAFE_DELETE(newObj);
	return nullptr;
}

bool StateMachine::init(Entity* owner)
{
	if (!Node::init())
	{
		log("Init StateMachine failed!");
		return false;
	}
	this->_owner = owner;

	this->scheduleUpdate();
	return true;
}

void StateMachine::addState(std::string stateName, State* state)
{
	if (_states.find(stateName) != _states.end())
	{
		return;
	}

	_states.insert({ stateName, state });
}

void StateMachine::removeState(std::string stateName)
{
	if (_states.find(stateName) == _states.end())
	{
		return;
	}
	_states.erase(stateName);
}

void StateMachine::setCurrentState(std::string stateName)
{
	if (_states.find(stateName) == _states.end())
	{
		log("error!");
		return;
	}
	this->_currentState = stateName;
}

void StateMachine::update(float dt)
{
	std::string newState = _states[_currentState]->updateState();
	if (newState != _currentState)
	{
		_states[_currentState]->exitState();
		_currentState = newState;
		_states[_currentState]->enterState(_owner);
	}
}

void StateMachine::onEnter()
{
	Node::onEnter();
	_states[_currentState]->enterState(_owner);
}
