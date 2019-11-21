#pragma once

#include "cocos2d.h"
#include <map>
#include "keyboard.h"
#include "Bullet.h"
#include "bullet.h"

class Bullet;

class Player : public cocos2d::Sprite {
private:

	cocos2d::Action* _idleAnimation;
	cocos2d::Action* _explosionAnimation;

	// Controlador
	KeyBoard* _control;

	// Balas
	cocos2d::Vector<Bullet*> Balas;
	int _numbullets = 100000;
	void shoot();

	void createIdleAnimation();
	void createExplosionAnimation();

public:
	enum Animations {
		IDLE = 0, EXPLOSION = 1
	};

	CC_SYNTHESIZE(Animations, _currentAnimation, _currentAnimation);
	CC_SYNTHESIZE(float, _speed, Speed);
	CREATE_FUNC(Player);
	//Player();

	// Colision
	void setCurrentAnimation(Animations anim);

	virtual bool init();
	void update(float);

	// Variables para disparos
	int bulletsact = 0;
	bool vuelta = 0;
};

