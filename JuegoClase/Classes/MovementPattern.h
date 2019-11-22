#pragma once

#include "cocos2d.h"

class MovementPattern
{
	auto sequence;
	void addMove(float duration, cocos2d::Point delta);
	auto getPattern();
};