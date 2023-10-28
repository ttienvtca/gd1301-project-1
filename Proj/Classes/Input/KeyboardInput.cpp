#include "KeyboardInput.h"

KeyboardInput* KeyboardInput::_instance;

KeyboardInput* KeyboardInput::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new KeyboardInput();
		_instance->init();
		_instance->retain();
	}

	return _instance;
}

bool KeyboardInput::init()
{
	if (!Node::init())
	{
		log("Init KeyboardInput failed!");
		return false;
	}

	this->addKey(EventKeyboard::KeyCode::KEY_W);
	this->addKey(EventKeyboard::KeyCode::KEY_A);
	this->addKey(EventKeyboard::KeyCode::KEY_S);
	this->addKey(EventKeyboard::KeyCode::KEY_D);

	this->addKey(EventKeyboard::KeyCode::KEY_DOWN_ARROW);
	this->addKey(EventKeyboard::KeyCode::KEY_LEFT_ARROW);
	this->addKey(EventKeyboard::KeyCode::KEY_RIGHT_ARROW);
	this->addKey(EventKeyboard::KeyCode::KEY_UP_ARROW);


	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(KeyboardInput::onKeyPress, this);
	listener->onKeyReleased = CC_CALLBACK_2(KeyboardInput::onKeyReleased, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

void KeyboardInput::addKey(EventKeyboard::KeyCode key)
{
	if (_keys.find(key) != _keys.end()) return;
	
	_keys.insert(std::pair<EventKeyboard::KeyCode, bool>(key, false));
}

void KeyboardInput::removeKey(EventKeyboard::KeyCode key)
{
	if (_keys.find(key) != _keys.end()) return;
	_keys.erase(key);
}

bool KeyboardInput::getKey(EventKeyboard::KeyCode key)
{
	if (_keys.find(key) == _keys.end()) return false;
	return _keys[key];
}

Vec2 KeyboardInput::getDirection()
{
	return Vec2(_horizontal, _vertical);
}

void KeyboardInput::onKeyPress(EventKeyboard::KeyCode key, Event* ev)
{
	if (_keys.find(key) == _keys.end()) return;
	_keys[key] = true;

	switch (key)
	{
	case EventKeyboard::KeyCode::KEY_A:
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		_horizontal = -1;
		break;
	case EventKeyboard::KeyCode::KEY_W:
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		_vertical = 1;
		break;
	case EventKeyboard::KeyCode::KEY_D:
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_horizontal = 1;
		break;
	case EventKeyboard::KeyCode::KEY_S:
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		_vertical = -1;
		break;
	default:
		break;
	}
}

void KeyboardInput::onKeyReleased(EventKeyboard::KeyCode key, Event* ev)
{
	if (_keys.find(key) == _keys.end()) return;
	_keys[key] = false;

	switch (key)
	{
	case EventKeyboard::KeyCode::KEY_A:
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		if (getKey(EventKeyboard::KeyCode::KEY_RIGHT_ARROW) || getKey(EventKeyboard::KeyCode::KEY_D))
			_horizontal = 1;
		else
			_horizontal = 0;
		break;
	case EventKeyboard::KeyCode::KEY_W:
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		if (getKey(EventKeyboard::KeyCode::KEY_S) || getKey(EventKeyboard::KeyCode::KEY_DOWN_ARROW))
			_vertical = 1;
		else
			_vertical = 0;
		break;
	case EventKeyboard::KeyCode::KEY_D:
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		if (getKey(EventKeyboard::KeyCode::KEY_A) || getKey(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
			_horizontal = -1;
		else
			_horizontal = 0;
		break;
	case EventKeyboard::KeyCode::KEY_S:
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		if (getKey(EventKeyboard::KeyCode::KEY_W) || getKey(EventKeyboard::KeyCode::KEY_UP_ARROW))
			_vertical = -1;
		else
			_vertical = 0;
		break;
	default:
		break;
	}
}
