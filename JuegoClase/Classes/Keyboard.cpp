#include "keyboard.h"

USING_NS_CC;

bool KeyBoard::init() {
	//super first
	if (!Node::init()) {
		return false;
	}

	auto eventlistener = EventListenerKeyboard::create();
	eventlistener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event) {
		if (keys.find(keycode) == keys.end()) {
			keys[keycode] = true;
		}
	};
	eventlistener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event) {
		keys.erase(keycode);
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventlistener, this);
	this->scheduleUpdate();


	return true;
}

bool KeyBoard::isKeyPressed(EventKeyboard::KeyCode code) {
	if (keys.find(code) != keys.end())
		return true;
	return false;
};

std::map<cocos2d::EventKeyboard::KeyCode, bool> KeyBoard::keys;

void KeyBoard::update(float delta) {
}


