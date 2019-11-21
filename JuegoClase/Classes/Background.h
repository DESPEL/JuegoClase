#pragma once

#include "cocos2d.h"

class Background : public cocos2d::Node {
private:
	CC_SYNTHESIZE(float, _speed, Speed);
	cocos2d::Size _screen;
	cocos2d::Sprite* _bgPart1;
	cocos2d::Sprite* _bgPart2;
	Background();

public:
	void update(float);
	~Background();
	CREATE_FUNC(Background);
};