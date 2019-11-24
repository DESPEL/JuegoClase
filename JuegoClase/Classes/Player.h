#pragma once

#include "cocos2d.h"
#include <map>
#include "keyboard.h"
#include "Bullet.h"
//#include "Player\Changuito.h"

class Bullet;

class Player : public cocos2d::Sprite {
protected:

	cocos2d::Action* _idleAnimation;
	cocos2d::Action* _explosionAnimation;

	// Controlador
	KeyBoard* _control;

	// Balas
	
	int _numbullets = 1000;
	void shoot(cocos2d::Vec2);
	float delay = 0;
	float delayvalue = 0.25;
	int change = 4;


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
	cocos2d::Vector<Bullet*> Balas;

	int kills = 0;
};

