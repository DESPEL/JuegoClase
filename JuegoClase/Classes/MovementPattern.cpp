#include "MovementPattern.h"

USING_NS_CC;

void MovementPattern::addMove(float duration, Point delta) {
	this->movements.pushBack(MoveBy::create(duration, delta));
}

auto MovementPattern::getPattern() {
	return Sequence::create();
}



