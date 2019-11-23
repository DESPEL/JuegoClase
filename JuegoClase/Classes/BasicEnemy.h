#pragma once

#include "cocos2d.h"

class BasicEnemy : public cocos2d::Sprite {
private:
	cocos2d::Action* _idleAnimation;
	cocos2d::Action* _explosionAnimation;

	void createIdleAnimation();
	void createExplosionAnimation();

	float DyingTime = 0.90;

public:
	enum Animations {
		IDLE = 0, EXPLOSION = 1
	};

	void setCurrentAnimation(Animations anim);
	void explode();

	CC_SYNTHESIZE(Animations, _currentAnimation, _currentAnimation);
	CC_SYNTHESIZE(float, _speed, Speed);
	CREATE_FUNC(BasicEnemy);

	virtual bool init();
	void update(float);

};

