#ifndef __KEYBOARD_INPUT_H__
#define __KEYBOARD_INPUT_H__

#include "cocos2d.h"

USING_NS_CC;

class KeyboardInput : public Node
{
public:
	static KeyboardInput* getInstance();

	void addKey(EventKeyboard::KeyCode key);
	void removeKey(EventKeyboard::KeyCode key);
	bool getKey(EventKeyboard::KeyCode key);

	Vec2 getDirection();
private:
	bool init() override;
	void onKeyPress(EventKeyboard::KeyCode key, Event* ev);
	void onKeyReleased(EventKeyboard::KeyCode key, Event* ev);

private:
	std::map<EventKeyboard::KeyCode, bool> _keys;
	float _horizontal, _vertical;
	static KeyboardInput* _instance;


};

#endif // !__KEYBOARD_INPUT_H__
