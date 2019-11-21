#pragma once

#include <cocos2d.h>

class KeyBoard : public cocos2d::Node {
public:

	virtual bool init();
	void update(float);

	static std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);

	CREATE_FUNC(KeyBoard);
};
