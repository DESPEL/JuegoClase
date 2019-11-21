#pragma once

#include "cocos2d.h"

class MovementPattern
{
	cocos2d::Vector<cocos2d::MoveBy*> movements;
	void addMove(float duration, cocos2d::Point delta);
	auto getPattern();
};

